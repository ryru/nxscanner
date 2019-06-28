# NXScanner Examples

Check out `./nxs --help` to get a list of all functionality.

## How to scan domains

Pass a domain as parameter:

    $ ./nxs example.com
    Starting NXScanner 1.1 at 2019-06-28 19:04 CEST
     example.com is okay
    
    NXScanner done: 1 domain scanned with 0 potential DNS block in 0.01 seconds


Or pass multiple domains as parameter:

    $ ./nxs example.com example.org github.com
    Starting NXScanner 1.1 at 2019-06-28 19:04 CEST
     example.com is okay
     example.org is okay
     github.com is okay
    
    NXScanner done: 3 domain scanned with 0 potential DNS block in 1.29 seconds


If you have a file with domains, you can pass it with the `-i` or `--input` parameter. Each domains has to be on a new line:

    $ ./nxs -i list.txt 
    Starting NXScanner 1.1 at 2019-06-28 19:04 CEST
     addere.ch is okay
     example.com is okay
     example.org is okay
     hsr.ch is okay
     switch.ch is okay
    
    NXScanner done: 5 domain scanned with 0 potential DNS block in 0.19 seconds


## Potentially blocked domain

Assume _example.com_ is blocked. The result would look like this:

    $ ./nxs -i list.txt 
    Starting NXScanner 1.1 at 2019-06-28 19:04 CEST
     addere.ch is okay
     hsr.ch is okay
     switch.ch is okay
    !example.com is potentially DNS blocked
     example.org is okay
    
    NXScanner done: 5 domain scanned with 1 potential DNS block in 1.64 seconds

