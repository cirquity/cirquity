# daemon runs in the background
# run something like tail /var/log/cirquityd/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/cirquityd:/var/lib/cirquityd -v $(pwd)/wallet:/home/cirquity --rm -ti cirquity:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG CIRQUITY_BRANCH=master
ENV CIRQUITY_BRANCH=${CIRQUITY_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/cirquity/cirquity.git /src/cirquity && \
    cd /src/cirquity && \
    git checkout $CIRQUITY_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/cirquityd /usr/local/bin/cirquityd && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/cirquity-wallet /usr/local/bin/cirquity-wallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/cirquityd && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/cirquity-wallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/cirquity && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the cirquityd service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/cirquityd cirquityd && \
    useradd -s /bin/bash -m -d /home/cirquity cirquity && \
    mkdir -p /etc/services.d/cirquityd/log && \
    mkdir -p /var/log/cirquityd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/cirquityd/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/cirquityd/run && \
    echo "cd /var/lib/cirquityd" >> /etc/services.d/cirquityd/run && \
    echo "export HOME /var/lib/cirquityd" >> /etc/services.d/cirquityd/run && \
    echo "s6-setuidgid cirquityd /usr/local/bin/cirquityd" >> /etc/services.d/cirquityd/run && \
    chmod +x /etc/services.d/cirquityd/run && \
    chown nobody:nogroup /var/log/cirquityd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/cirquityd/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/cirquityd/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/cirquityd" >> /etc/services.d/cirquityd/log/run && \
    chmod +x /etc/services.d/cirquityd/log/run && \
    echo "/var/lib/cirquityd true cirquityd 0644 0755" > /etc/fix-attrs.d/cirquityd-home && \
    echo "/home/cirquity true cirquity 0644 0755" > /etc/fix-attrs.d/cirquity-home && \
    echo "/var/log/cirquityd true nobody 0644 0755" > /etc/fix-attrs.d/cirquityd-logs

VOLUME ["/var/lib/cirquityd", "/home/cirquity","/var/log/cirquityd"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/cirquity export HOME /home/cirquity s6-setuidgid cirquity /bin/bash"]
