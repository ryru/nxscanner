#ifndef NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
#define NXSCANNER_INCLUDE_SCANNER_SCANNER_H_

#include "probe_set.h"
#include "resolver.h"

#include <algorithm>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace nxscan::scanner {

class Scanner {
 public:
  explicit Scanner(std::vector<nxscan::scanner::Probes> &all_probes) : all_probes{all_probes} {
    scan();
  }
 private:
  void scan() {
    std::for_each(all_probes.begin(), all_probes.end(), [&](nxscan::scanner::Probes &p) {
      boost::asio::io_service io_service;
      nxscan::scanner::Resolver resolver1{io_service, p.get_t1_domain()};
      nxscan::scanner::Resolver resolver2{io_service, p.get_t2_host()};
      nxscan::scanner::Resolver resolver3{io_service, p.get_t3_random()};
      io_service.run();
    });
  }

  std::vector<nxscan::scanner::Probes> &all_probes;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
