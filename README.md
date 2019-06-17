[![Build Status](https://travis-ci.org/ryru/nxscanner.svg?branch=master)](https://travis-ci.org/ryru/nxscanner.svg?branch=master)


# NXScanner

A DNS blocking detection application using DNS-only.

NXScanner helps detecting potential DNS blocking systems in your current network.


## Overview

DNS based blocking systems, as used in BYOD networks (such as public WiFi) or at ISP, do not resolve blacklisted domain names properly. Instead of resolving the correct IP address of a requested domain name, these systems either send nothing, an error or an IP address leading to a blocking web server.

While the first two reactions are relatively easy to detect, the third is a little harder.

NXScanner helps with all three reactions and prints out which domains are potentially blocked in your current network.

    
     +----------+  example.com  +------------------+       +---------------------+
     |  CLIENT  +--------------->   DNS RESOLVER   |       |   www.example.com   |
     +----^-----+               +------------------+       |   IP: A             |
          |                        |                       +---------------------+
          +------------------------+
                     IP: B                                 +---------------------+
                                                           |   BLOCKING SERVER   |
                                                           |   IP: B             |
                                                           +---------------------+




## Usage

    $ ./nxscanner 
    NXScanner version 1.0
    usage: nxscanner [-i FILE] [DOMAIN]...
      --domain DOMAIN	domain names to scan
      -i, --input FILE	read domain names from FILE
      -v, --version		print version
      -h, --help		print help
    

## Example

Pass one or multiple domains to scan to nxscanner:

    $ ./nxscanner example.com github.com
    Starting NXScanner
     example.com is okay
     github.com is okay
    
    NXScanner done: 2 domain scanned with 0 potential DNS blocks in 0.07 seconds


Pass one or multiple lists with domains plus additional domains to scan:

    $ ./nxscanner -i list.txt example.com example.org
    Starting NXScanner
     addere.ch is okay
     hsr.ch is okay
     switch.ch is okay
     example.com is okay
     example.org is okay
    
    NXScanner done: 5 domain scanned with 0 potential DNS block in 0.16 seconds


If _example.com_ is blocked:

    $ ./nxscanner -i list.txt example.com example.org
    Starting NXScanner
     addere.ch is okay
     hsr.ch is okay
     switch.ch is okay
    !example.com is  potentially DNS blocked
     example.org is okay
    
    NXScanner done: 5 domain scanned with 1 potential DNS block in 0.16 seconds

## Scan Details

For each domain three DNS requests are sent to the DNS resolver. For example to test whether _example.com_ is blocked or not, the following requests are sent:

1. `example.com`
2. `www.example.com`
3. `<random>.example.com`

`<random>` stands for a random string.

If _example.com_  is not blocked by a DNS resolver, the first two will resolve into an IP address whereas the third will result in an NXDOMAIN error.

Otherwise the blocking system sends either nothing, three NXDOMAIN or three IP addresses to its blocking web server.


## False Positives

Be aware, false-positives do exist. If a configuration of an authoritative name server sends back an IP address for every valid and invalid domain name, the scan method detects a potential block. For this reason every DNS block detection in the scan output is tagged _potentially DNS block_ detected.

However, the false positive rate is relatively low:

- Currently 4.6% false-positives in .CH Top 1000 domains
- Currently 3% false-positives in Alexa Top 100 domains


## Compile DIY

### Linux
This instruction is for Ubuntu Linux but should be similar in other distributions.

Requirements:

- Git `git --version`
  - if not installed: `$ sudo apt install git`
- Cmake version >= 3.5.1 `$ cmake --version`
  - if not installed: `$ sudo apt install cmake`
- Boost C++ Library `$ apt -qq list libboost-all-dev`
  - if not installed: `sudo apt install libboost-all-dev`

1. `git clone https://github.com/ryru/nxscanner.git`
2. `cd nxscanner`
3. `mkdir build`
4. `cd build/`
5. `cmake ..`
6. `cmake --build .`

That's it: `./bin/nxscanner --version`
