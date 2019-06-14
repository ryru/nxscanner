#include "nxscan.h"

void nxscan::Nxscan::start() {
  // generate data set
  all_probes = nxscan::scanner::get_probes(all_domains);

  // scan
  nxscan::scanner::Scanner scanner{all_probes};
  start_time = std::chrono::high_resolution_clock::now();
  scanner.scan();
  end_time = std::chrono::high_resolution_clock::now();
}
std::chrono::duration<double> nxscan::Nxscan::get_elapsed() {
  return end_time - start_time;
}
const std::vector<nxscan::scanner::Probes> nxscan::Nxscan::get_probe_results() {
  return all_probes;
}
