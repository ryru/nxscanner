#include "nxscan.h"

void nxscan::Nxscan::start() {
  // generate data set
  allProbes = nxscan::scanner::getProbes(allDomain);

  // scan
  nxscan::scanner::Scanner scanner{allProbes};
  timeStart = std::chrono::high_resolution_clock::now();
  scanner.scan();
  timeEnd = std::chrono::high_resolution_clock::now();
}
std::chrono::duration<double> nxscan::Nxscan::getElapsedTime() {
  return timeEnd - timeStart;
}
std::vector<nxscan::scanner::Probes> nxscan::Nxscan::getProbeResults() {
  return allProbes;
}
