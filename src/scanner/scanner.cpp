#include "scanner/scanner.h"

#include <algorithm>

void nxscan::scanner::Scanner::scan() {
  std::for_each(all_probes.begin(), all_probes.end(), [&](nxscan::scanner::Probes &p) {
    boost::asio::io_service io_service;
    nxscan::scanner::Resolver resolver1{io_service, p.get_t1_domain()};
    resolver1.resolve();
    nxscan::scanner::Resolver resolver2{io_service, p.get_t2_host()};
    resolver2.resolve();
    nxscan::scanner::Resolver resolver3{io_service, p.get_t3_random()};
    resolver3.resolve();
    io_service.run();
  });

}
