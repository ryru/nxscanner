#ifndef NXSCANNER_INCLUDE_NXSCAN_H_
#define NXSCANNER_INCLUDE_NXSCAN_H_

#include "scanner/preparation.h"
#include "scanner/probe_set.h"
#include "scanner/scanner.h"

#include <chrono>
#include <vector>

namespace nxscan {

class Nxscan {

 public:
  explicit Nxscan(std::vector<std::string> &all_domains) : all_domains{all_domains} {
    start();
  }

  std::chrono::duration<double> get_elapsed() {
    return end_time - start_time;
  }

  const std::vector<nxscan::scanner::Probes> get_probe_results() {
    return all_probes;
  }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
  std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
  std::vector<std::string> all_domains;
  std::vector<nxscan::scanner::Probes> all_probes;

  void start() {
    // generate data set
    nxscan::scanner::Preparation preparation(all_domains);
    all_probes = preparation.get_probes();

    // scan
    start_time = std::chrono::high_resolution_clock::now();
    nxscan::scanner::Scanner{all_probes};
    end_time = std::chrono::high_resolution_clock::now();
  }

};

}

#endif //NXSCANNER_INCLUDE_NXSCAN_H_
