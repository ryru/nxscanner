#include "nxscan.h"
#include "validator/display.h"
#include "validator/input.h"

#include <iomanip>
#include <iostream>

int main(int argc, char **argv) {
  std::variant<std::vector<std::string>, std::string> returnVariants = nxscan::validator::parse(argc, argv);
  try {
    std::get<std::vector<std::string>>(returnVariants);
  } catch (const std::bad_variant_access &) {
    std::cout << std::get<std::string>(returnVariants) << '\n';
    return EXIT_FAILURE;
  }

  std::cout << "Starting NXScanner\n";
  nxscan::Nxscan scanner{std::get<std::vector<std::string>>(returnVariants)};
  scanner.start();
  auto elapsed = scanner.getElapsedTime();
  auto allProbes = scanner.getProbeResults();

  nxscan::validator::Display display{std::cout, allProbes};
  display.print();

  std::cout << "\nNXScanner done: " << display.getDomainTotal() << " domain scanned with "
            << display.getBlockedDomainTotal()
            << " potential DNS block in " << std::fixed << std::setprecision(2) << elapsed.count() << " seconds\n";

}