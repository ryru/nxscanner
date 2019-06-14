#include "nxscan.h"
#include "validator/display.h"
#include "validator/input.h"
#include <iomanip>
#include <iostream>

int main(int argc, char **argv) {
  try {
    std::vector<std::string> all_domains = nxscan::validator::parse(std::cout, argc, argv);

    std::cout << "Starting NXScanner\n";
    nxscan::Nxscan scanner{all_domains};
    scanner.start();
    auto elapsed = scanner.get_elapsed();
    auto all_probes = scanner.get_probe_results();

    nxscan::validator::Display display{std::cout, all_probes};
    display.print();

    std::cout << "\nNXScanner done: " << display.get_hostname_total() << " domain scanned with "
              << display.get_dns_blocks()
              << " potential DNS block in " << std::fixed << std::setprecision(2) << elapsed.count() << " seconds\n";

  } catch (const std::exception &) {
    return EXIT_FAILURE;
  }
}