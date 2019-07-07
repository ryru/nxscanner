#include "nxscan.h"

void nxs::Nxscan::start() {
  // generate data set
  allProbes = nxs::scanner::getProbes(allDomain);

  // scan
  nxs::scanner::Scanner scanner{allProbes};
  timeStart = std::chrono::high_resolution_clock::now();
  scanner.scan();
  timeEnd = std::chrono::high_resolution_clock::now();
}
std::chrono::duration<double> nxs::Nxscan::getElapsedTime() {
  return timeEnd - timeStart;
}
std::vector<nxs::scanner::Probes> nxs::Nxscan::getProbeResults() {
  return allProbes;
}
