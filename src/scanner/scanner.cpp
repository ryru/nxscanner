#include "scanner/scanner.h"

#include <algorithm>

std::vector<nxscan::scanner::Resolver> prepareScan(std::vector<nxscan::scanner::Probes> &allProbes,
                                                   boost::asio::io_service &io_service) {
  std::vector<nxscan::scanner::Resolver> allResolvers{};
  std::for_each(allProbes.begin(), allProbes.end(), [&](nxscan::scanner::Probes &p) {
    allResolvers.emplace_back(io_service, p.getDomain());
    allResolvers.emplace_back(io_service, p.getHost());
    allResolvers.emplace_back(io_service, p.getRandomHost());
  });
  return allResolvers;
}

void nxscan::scanner::Scanner::scan() {
  boost::asio::io_service io_service;
  auto allResolvers = prepareScan(allProbes, io_service);

  std::for_each(std::begin(allResolvers), std::end(allResolvers), [](auto &r) {
    r.resolve();
  });

  io_service.run();
}
