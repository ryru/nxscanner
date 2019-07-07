#include "nxs.h"
#include "nxscan.h"
#include "validator/display.h"
#include "validator/input.h"

#include <iomanip>

static void printStart(std::ostream &out) {
  std::string const versionString = std::to_string(nxs::versionMajor) + '.' + std::to_string(nxs::versionMinor);
  std::time_t const localtime = std::time(nullptr);
  out << "Starting NXScanner " + versionString + " at "
      << std::put_time(std::localtime(&localtime), "%Y-%m-%d %H:%M %Z") << '\n';
}

static void printSummary(std::ostream &out,
                         uint32_t const totalDomains,
                         uint32_t const totalBlockedDomains,
                         double const timeElapsed) {
  out << "\nNXScanner done: " << totalDomains << " domain scanned with " << totalBlockedDomains
      << " potential DNS block in " << std::fixed << std::setprecision(2) << timeElapsed << " seconds\n";
}

namespace nxs {
int nxsScanner(std::ostream &out, int argc, char **argv) {
  std::variant<std::vector<std::string>, std::string> returnVariants = nxs::validator::parse(argc, argv);
  try {
    std::get<std::vector<std::string>>(returnVariants);
  } catch (const std::bad_variant_access &) {
    out << std::get<std::string>(returnVariants) << '\n';
    return EXIT_FAILURE;
  }

  printStart(out);
  nxs::Nxscan scanner{std::get<std::vector<std::string>>(returnVariants)};
  scanner.start();
  auto elapsed = scanner.getElapsedTime();
  auto allProbes = scanner.getProbeResults();

  nxs::validator::Display display{out, allProbes};
  display.print();
  printSummary(out, display.getDomainTotal(), display.getBlockedDomainTotal(), elapsed.count());
  return EXIT_SUCCESS;
}
}