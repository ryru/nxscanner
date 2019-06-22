#include "validator/input.h"
#include "nxs.h"

#include <algorithm>
#include <boost/program_options.hpp>
#include <fstream>

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
      while (std::getline(infile, line)) {
        allDomains.push_back(line);
      }
    });

  }

  if (vm.count("domain")) {
    auto listOfDomains = vm["domain"].as<std::vector<std::string>>();
    std::for_each(listOfDomains.begin(), listOfDomains.end(), [&](std::string &domain) {
      allDomains.push_back(domain);
    });

  }

  return allDomains;
}
