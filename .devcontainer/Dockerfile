FROM ubuntu

USER root

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install git -y
RUN apt-get install wget -y
RUN apt-get install nodejs -y
RUN apt-get install python3 -y

# Install arduino-cli:
RUN  wget -O /tmp/cli.tar.gz https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Linux_64bit.tar.gz
RUN  tar -C /usr/local/bin -zxvf /tmp/cli.tar.gz
RUN  rm /tmp/cli.tar.gz

RUN arduino-cli core install arduino:avr
RUN arduino-cli core search zumo --additional-urls "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json,https://files.pololu.com/arduino/package_pololu_index.json"
RUN arduino-cli core install pololu-a-star:avr --additional-urls "https://files.pololu.com/arduino/package_pololu_index.json"
RUN arduino-cli core install esp32:esp32 --additional-urls "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"
