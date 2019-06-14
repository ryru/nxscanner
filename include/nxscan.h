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
  explicit Nxscan(std::vector<std::string> &all_domains) : all_domains{all_domains} {}

  void start();
  std::chrono::duration<double> get_elapsed();
  const std::vector<nxscan::scanner::Probes> get_probe_results();

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
  std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
  std::vector<std::string> all_domains;
  std::vector<nxscan::scanner::Probes> all_probes;


};

}

#endif //NXSCANNER_INCLUDE_NXSCAN_H_
