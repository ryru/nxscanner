# NXScanner

A DNS blocking detection application using DNS-only.

NXScanner helps detecting potential DNS blocking systems in your current network.


## Usage

    ./nxscanner 
    NXScanner options:
      --domain arg          domain names to scan
      -i [ --input ] arg    read domains from file
      -v [ --version ]      print version
      -h [ --help ]         print help


## Example

    $ ./nxscanner example.com github.com
    Starting NXScanner
     example.com is okay
     github.com is okay
    
    NXScanner done: 2 domain scanned with 0 potential DNS blocks in 0.07 seconds


## Overview

DNS based blocking systems, as used in BYOD networks (such as public wifi) or at ISP, do not resolve blacklisted domain names properly. Instead of sending the correct ip address of a requested internet resource these systems send either an nothing, an error or a wrong ip address, leading to a blocking site, back to the client.

While the first two reactions are relatively easy to detect, the third is a little more trickier.

NXScanner helps with all three reactions and prints out which domains are potentially blocked in your current network.


## Scan Details

For each domain three DNS requests will be send to the DNS resolver, e.g _example.com_:

1. `example.com`
2. `www.example.com`
3. `random.example.com`

`random` stands for a random five character string.

If _example.com_  is not blocked by a DNS resolver the first two will resolve into an ip address where as the third will result in an NXDOMAIN error.

Otherwise the blocking system sends either nothing, three NXDOMAIN or three ip addresses to its blocking web server.
