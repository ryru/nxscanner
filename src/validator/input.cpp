#include "validator/input.h"
#include "nxs.h"

#include <algorithm>
#include <boost/program_options.hpp>
#include <fstream>
#include <set>

using namespace boost::program_options;

static const std::string getVersion() {
  return std::string{"NXScanner version " + std::to_string(versionMajor) + '.' + std::to_string(versionMinor) + '\n'};
}

static const std::string getHelp() {
  std::string help{getVersion()};
  help.append("usage: nxscanner [-i FILE] [DOMAIN]...\n");
  help.append("  --domain DOMAIN\tdomain names to scan\n");
  help.append("  -i, --input FILE\tread domain names from FILE\n");
  help.append("  -v, --version\t\tprint version\n");
  help.append("  -h, --help\t\tprint help\n");
  return help;
}

void addAllElements(std::vector<std::string> &domainsToScan, std::set<std::string> const &inputData) {
  std::copy_if(std::begin(inputData),
               std::end(inputData),
               std::back_inserter(domainsToScan),
               [](std::string const &domain) {
                 return !(domain.size() < 4 || (domain.find('.') == std::string::npos));
               });
}

std::variant<std::vector<std::string>, std::string> nxscan::validator::parse(int argc, char **argv) {
  options_description desc{"NXScanner options"};
  desc.add_options()
      ("domain", value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "domain names to scan")
      ("input,i", value<std::vector<std::string>>(), "read domains from file")
      ("version,v", "print version")
      ("help,h", "print help");

  positional_options_description pos_desc;
  pos_desc.add("domain", -1);

  command_line_parser parser{argc, argv};
  parser.options(desc).positional(pos_desc).allow_unregistered();
  parsed_options parsed_options = parser.run();

  variables_map vm;
  store(parsed_options, vm);
  notify(vm);
  if (vm.count("help") or argc <= 1) {
    return getHelp();
  } else if (vm.count("version")) {
    return getVersion();
  }

  std::vector<std::string> allDomains;
  if (vm.count("input")) {
    auto listOfFiles = vm["input"].as<std::vector<std::string>>();
    std::for_each(listOfFiles.begin(), listOfFiles.end(), [&](std::string &filePath) {
      std::ifstream infile{filePath};
      std::string line;
      std::set<std::string> listOfDomains{};
      while (std::getline(infile, line)) {
        if (line.at(0) != '#') {
          listOfDomains.insert(line);
        }
      }
      addAllElements(allDomains, listOfDomains);
    });

  }

  if (vm.count("domain")) {
    auto listOfDomains = vm["domain"].as<std::vector<std::string>>();
    std::set<std::string> s{};
    std::copy(std::begin(listOfDomains), std::end(listOfDomains), std::inserter(s, std::begin(s)));
    addAllElements(allDomains, s);
  }

  return allDomains;
}
