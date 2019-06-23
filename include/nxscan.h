#ifndef NXSCANNER_INCLUDE_NXSCAN_H_
#define NXSCANNER_INCLUDE_NXSCAN_H_

#include "scanner/preparation.h"
#include "scanner/probe_set.h"
#include "scanner/scanner.h"

#include <chrono>
#include <string>
#include <vector>

namespace nxscan {

class Nxscan {

 public:
  explicit Nxscan(std::vector<std::string> const &allDomain) : allDomain{allDomain} {}

  void start();
  std::chrono::duration<double> getElapsedTime();
  std::vector<nxscan::scanner::Probes> getProbeResults();

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> timeStart;
  std::chrono::time_point<std::chrono::high_resolution_clock> timeEnd;
  std::vector<std::string> const allDomain;
  std::vector<nxscan::scanner::Probes> allProbes;


};

}

#endif //NXSCANNER_INCLUDE_NXSCAN_H_
