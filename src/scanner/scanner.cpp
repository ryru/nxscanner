#include "scanner/scanner.h"

#include <algorithm>

using nxscan::scanner::Probes;
using nxscan::scanner::Resolver;

std::vector<Resolver> prepareScan(std::vector<Probes> &allProbes,
                                  boost::asio::io_service &ioService1,
                                  boost::asio::io_service &ioService2,
                                  boost::asio::io_service &ioService3) {
  std::vector<Resolver> allResolvers{};
  std::for_each(allProbes.begin(), allProbes.end(), [&](Probes &p) {
    Resolver r1{ioService1, p.getDomain()};
    Resolver r2{ioService2, p.getHost()};
    Resolver r3{ioService3, p.getRandomHost()};
    allResolvers.push_back(std::move(r1));
    allResolvers.push_back(std::move(r2));
    allResolvers.push_back(std::move(r3));
  });
  return allResolvers;
}

void nxscan::scanner::Scanner::scan() {
  boost::asio::io_service ioService1;
  boost::asio::io_service ioService2;
  boost::asio::io_service ioService3;
  auto allResolvers = prepareScan(allProbes, ioService1, ioService2, ioService3);

  std::for_each(std::begin(allResolvers), std::end(allResolvers), [](Resolver &r) {
    r.resolve();
  });

  ioService1.run();
  ioService2.run();
  ioService3.run();
}
