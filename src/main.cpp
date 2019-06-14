#include "nxscan.h"
#include "validator/display.h"
#include "validator/input.h"
#include <iomanip>
#include <iostream>

int main(int argc, char **argv) {
  try {
    std::vector<std::string> allDomains = nxscan::validator::parse(std::cout, argc, argv);

    std::cout << "Starting NXScanner\n";
    nxscan::Nxscan scanner{allDomains};
    scanner.start();
    auto elapsed = scanner.getElapsedTime();
    auto allProbes = scanner.getProbeResults();

    nxscan::validator::Display display{std::cout, allProbes};
    display.print();

    std::cout << "\nNXScanner done: " << display.getDomainTotal() << " domain scanned with "
              << display.getBlockedDomainTotal()
              << " potential DNS block in " << std::fixed << std::setprecision(2) << elapsed.count() << " seconds\n";

  } catch (const std::exception &) {
    return EXIT_FAILURE;
  }
}