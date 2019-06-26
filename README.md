[![Build Status](https://travis-ci.org/ryru/nxscanner.svg?branch=master)](https://travis-ci.org/ryru/nxscanner.svg?branch=master)


# NXScanner

The goal of this project is to find out if one or multiple domain names are blocked by DNS systems. No direct communication is established between the scanner client and one of the server of a checked domain.

NXScanner tries to achieve this by using clever DNS queries. This DNS-only approach is very fast and causes no noise on servers of the checked domains. However, the results are less accurate.

This is a proof of concept project whose goal is to explore and further develop this lightweight scanning approach.


## Download Executable

You find the latest Linux 64 bit build in the [Release](https://github.com/ryru/nxscanner/releases) section.

Instructions on how to build the software for Linux and Windows can be found below in the section _Compile it yourself_.


## Usage

    $ ./nxs 
    NXScanner version 1.1
    usage: nxscanner [-i FILE] [DOMAIN]...
      --domain DOMAIN	domain names to scan
      -i, --input FILE	read domain names from FILE
      -v, --version		print version
      -h, --help		print help


Also check out the [examples](https://github.com/ryru/nxscanner/blob/master/EXAMPLES.md).


## Scan Method

If a DNS resolver does not block domains, it resolves the IP address properly. If, on the other hand, domains are blocked, it must perform one of the following reactions:

1. DNS resolver does not return a response and does nothing
2. DNS resolver returns an error message
3. DNS Resolver sends back a wrong IP address.

Reactions 1 and 2 are easy to detect in which DNS resolver does not respond a IP address for a valid domain. The 3 reaction is harder to detect and will be described here.


### Scope

The following assumptions are made:

1. The domain exists
2. In the zone file of the domain there is an entry for the host `www`
3. The name server responds with NXDOMAIN error messages for hosts and subdomains that do not exist.


### Scan

The method is basically based on the evaluation of DNS responses.

The _example.com_ domain is scanned.

    +------------+                                        +----------------+
    | NXS Client |                    example.com         |  DNS Resolver  |
    |            +---------------------------------------->                |
    |            |                www.example.com         |                |
    |            +---------------------------------------->                |
    |            |         random.www.example.com         |                |
    |            +---------------------------------------->                |
    +------------+                                        +----------------+


If the DNS resolver blocks the domain _example.com_ by returning a wrong IP address e.g. to a blocking page, it must reply to all three requests with the same IP address. The DNS resolver does not check if the hosts and sobdomains of the blocked domain actually exist.

In case _example.com_ is not blocked, the DNS resolver tries to find the IP addresses and asks the authoritative name server. For non-existent hosts or subdomains, it will respond with an NXDOMAIN error message.


### Limitations

This method is useful for finding out whether entire domains or subdomains are blocked. Individual hosts cannot be scanned.


### False Positives

Be aware, false-positives do exist. If a configuration of an authoritative name server sends back an IP address for every valid and invalid domain name, the scan method detects a potential block. For this reason every DNS block detection in the scan output is tagged _potentially DNS block_ detected.

Only few name servers do not answer with NXDOMAIN errors on invalid host or subdomains. Also some ISPs intercept DNS requests and answers IP addresses to non-existing DNS resources.


### Conclusion

This approach has little complexity and makes little demands on the client: being able to make DNS requests and evaluate their responses is enough to detect possible DNS blockages. No baseline information or third party systems are required.

Speed and simplicity are at the expense of accuracy. The false positive rate can certainly be further reduced by additional scanning methods.


## Compile it yourself

The source code is OS independent.


### Linux

This instruction is for Ubuntu Linux but should be similar in other distributions.

Requirements:

- Git `git --version`
  - if not installed: `sudo apt install git`
- Cmake version >= 3.5.1 `cmake --version`
  - if not installed: `sudo apt install cmake`
- Boost C++ Library `apt -qq list libboost-all-dev`
  - if not installed: `sudo apt install libboost-all-dev`

1. `git clone https://github.com/ryru/nxscanner.git`
2. `cd nxscanner`
3. `mkdir build`
4. `cd build/`
5. `cmake ..`
6. `cmake --build .`

That's it: `./bin/nxscanner --version`


### Windows

Requirements:

- Git 
- [MinGW](http://www.mingw.org/)
- Cmake version >= 3.5.1
- [Boost C++ Library](https://www.boost.org/)

1. `git clone https://github.com/ryru/nxscanner.git`
2. `cd nxscanner`
3. `mkdir build`
4. `cd build`
5. `cmake .. -G "MinGW Makefiles"`
6. `cmake --build .`

That's it: `bin\nxscanner --version`

