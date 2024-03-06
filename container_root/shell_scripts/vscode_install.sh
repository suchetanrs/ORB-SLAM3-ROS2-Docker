#!/bin/bash

cd "/tmp"
mkdir runtime-root
chmod a+rw runtime-root
cd "/root"
apt-get update
apt-get upgrade
apt update --fix-missing

#installing visual studio code
cd /root/
apt-get install wget gpg -y
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg
apt install apt-transport-https
apt-get update
apt update --fix-missing
apt install code -y
apt-get upgrade
rm -rf /var/lib/apt/lists/*