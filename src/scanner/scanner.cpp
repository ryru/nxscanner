#include "scanner/scanner.h"

#include <algorithm>

std::vector<nxscan::scanner::Resolver> prepareScan(std::vector<nxscan::scanner::Probes> &allProbes,
                                                   boost::asio::io_service &io_service1,
                                                   boost::asio::io_service &io_service2,
                                                   boost::asio::io_service &io_service3) {
  std::vector<nxscan::scanner::Resolver> allResolvers{};
  std::for_each(allProbes.begin(), allProbes.end(), [&](nxscan::scanner::Probes &p) {
    allResolvers.push_back(nxscan::scanner::Resolver{io_service1, p.getDomain()});
    allResolvers.push_back(nxscan::scanner::Resolver{io_service2, p.getHost()});
    allResolvers.push_back(nxscan::scanner::Resolver{io_service3, p.getRandomHost()});
  });
  return allResolvers;
}

void nxscan::scanner::Scanner::scan() {
  boost::asio::io_service io_service1;
  boost::asio::io_service io_service2;
  boost::asio::io_service io_service3;
  auto allResolvers = prepareScan(allProbes, io_service1, io_service2, io_service3);

  std::for_each(std::begin(allResolvers), std::end(allResolvers), [](nxscan::scanner::Resolver &r) {
    r.resolve();
  });

  io_service1.run();
  io_service2.run();
  io_service3.run();
}
