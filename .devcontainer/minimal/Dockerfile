FROM ubuntu

USER root

RUN apt-get install wget -y

# Install arduino-cli:
RUN  wget -O /tmp/cli.tar.gz https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Linux_64bit.tar.gz
RUN  tar -C /usr/local/bin -zxvf /tmp/cli.tar.gz
RUN  rm /tmp/cli.tar.gz

# Preinstall arduino boards
RUN arduino-cli core install arduino:avr

# Preinstall arduino libraries to cache
RUN arduino-cli lib install "ArduinoJson"

# Ignore doifferent line endings
# https://docs.github.com/en/get-started/getting-started-with-git/configuring-git-to-handle-line-endings
RUN git config --global core.autocrlf true
