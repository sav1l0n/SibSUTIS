#!/bin/bash

echo -e "OS          $(lsb_release -sd | tr -d '"')"
echo -e "Kernel      $(uname -sr)\n"

echo -e "CPU         $(lscpu | grep "Model name" | cut -d ':' -f2 | head -n 1 | xargs)"
echo -e "CPU MHz     $(cat /proc/cpuinfo | grep "Hz" | cut -d ':' -f2 | head -n 1 | xargs)"
echo -e "CPU Core    $(lscpu | grep "Core" | cut -d ':' -f2 | head -n 1 | xargs)"
echo -e "CPU Cache   $(cat /proc/cpuinfo | grep "cache" | cut -d ':' -f2 | head -n 1 | xargs)\n"

echo -e "RAM free    $(free --mega| grep "Mem" | xargs | cut -d " " -f4) MB"
echo -e "RAM total   $(free --mega| grep "Mem" | xargs | cut -d " " -f2) MB"
echo -e "RAM used    $(free --mega| grep "Mem" | xargs | cut -d " " -f3) MB\n"

echo -e "User        $(whoami)"
echo -e "IP address  $(ip -br a show | grep UP | xargs | cut -d " " -f3)"
echo -e "MAC address $(ip a | grep ether | tail -n 1 | xargs | cut -d " " -f3)\n"

echo -e "$(df -h | grep ^/dev/ | awk '{printf "%-10s %-10s %s/%s\n", $6, $2, $3, $4}')"