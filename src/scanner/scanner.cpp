#include "scanner/scanner.h"

#include <algorithm>

void nxscan::scanner::Scanner::scan() {
  std::for_each(allProbes.begin(), allProbes.end(), [&](nxscan::scanner::Probes &p) {
    boost::asio::io_service io_service;
    nxscan::scanner::Resolver resolver1{io_service, p.getDomain()};
    resolver1.resolve();
    nxscan::scanner::Resolver resolver2{io_service, p.getHost()};
    resolver2.resolve();
    nxscan::scanner::Resolver resolver3{io_service, p.getRandomHost()};
    resolver3.resolve();
    io_service.run();
  });

}
