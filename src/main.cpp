#include "nxs.h"
#include "nxscan.h"
#include "validator/display.h"
#include "validator/input.h"

#include <iomanip>
#include <iostream>

void printStart(std::ostream &out) {
  out << "Starting NXScanner " + std::to_string(versionMajor) + '.' + std::to_string(versionMajor) + '\n';
}

void printSummary(std::ostream &out,
                  uint32_t const totalDomains,
                  uint32_t const totalBlockedDomains,
                  double const timeElapsed) {
  out << "\nNXScanner done: " << totalDomains << " domain scanned with " << totalBlockedDomains
      << " potential DNS block in " << std::fixed << std::setprecision(2) << timeElapsed << " seconds\n";
}

int main(int argc, char **argv) {
  std::variant<std::vector<std::string>, std::string> returnVariants = nxscan::validator::parse(argc, argv);
  try {
    std::get<std::vector<std::string>>(returnVariants);
  } catch (const std::bad_variant_access &) {
    std::cout << std::get<std::string>(returnVariants) << '\n';
    return EXIT_FAILURE;
  }

  printStart(std::cout);
  nxscan::Nxscan scanner{std::get<std::vector<std::string>>(returnVariants)};
  scanner.start();
  auto elapsed = scanner.getElapsedTime();
  auto allProbes = scanner.getProbeResults();

  nxscan::validator::Display display{std::cout, allProbes};
  display.print();
  printSummary(std::cout, display.getDomainTotal(), display.getBlockedDomainTotal(), elapsed.count());
}