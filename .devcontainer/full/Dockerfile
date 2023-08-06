FROM ubuntu

USER root

RUN apt-get update -y
RUN apt-get upgrade -y

RUN apt-get install wget -y
RUN apt-get install curl -y
RUN apt-get install python3 -y
RUN apt-get install pip -y
RUN apt-get install nodejs -y

# Installing npm requires another apt-get update and upgrade
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install npm -y

# Install arduino-cli:
RUN  wget -O /tmp/cli.tar.gz https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Linux_64bit.tar.gz
RUN  tar -C /usr/local/bin -zxvf /tmp/cli.tar.gz
RUN  rm /tmp/cli.tar.gz

# Preinstall arduino boards
RUN arduino-cli core install arduino:avr
RUN arduino-cli core search zumo --additional-urls "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json,https://files.pololu.com/arduino/package_pololu_index.json"
RUN arduino-cli core install pololu-a-star:avr --additional-urls "https://files.pololu.com/arduino/package_pololu_index.json"
RUN arduino-cli core install esp32:esp32 --additional-urls "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"

# Preinstall arduino libraries to cache
RUN arduino-cli lib install "ArduinoJson"

# Preinstall python packages to cache
RUN pip install matplotlib
RUN pip install seaborn
RUN pip install pandas
RUN pip install numpy
RUN pip install flask
RUN pip install uncertainties

# Preinstall npm packages to cache
RUN npm install -g typescript
RUN npm install -g ts-node
RUN npm install -g express @types/express
RUN npm install -g dotenv
RUN npm install -g vsce
RUN npm install -g @types/node

# Ignore doifferent line endings
# https://docs.github.com/en/get-started/getting-started-with-git/configuring-git-to-handle-line-endings
RUN git config --global core.autocrlf true

# Install code-server
# https://linux.how2shout.com/install-code-server-for-vs-code-on-ubuntu-22-04-or-20-04-lts/
# RUN curl -fsSL https://code-server.dev/install.sh | sh

# Preinstall vscode extensions
# COPY devcontainer.json .
# COPY preinstall-extensions preinstall-extensions
# 
# RUN npm start --prefix preinstall-extensions
# 
# RUN rm devcontainer.json
# RUN rm preinstall-extensions
