#include "validator/input.h"

#include <algorithm>
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

using namespace boost::program_options;

std::vector<std::string> nxscan::validator::parse(std::ostream &out, int argc, char **argv) {
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
  std::vector<std::string> all_domains;
  if (vm.count("help") or argc <= 1) {
    out << desc << '\n';
    throw std::exception();
  } else if (vm.count("version")) {
    out << "NXScanner version 1.0\n";
    throw std::exception();
  }

  if (vm.count("input")) {

    auto listOfFiles = vm["input"].as<std::vector<std::string>>();
    std::for_each(listOfFiles.begin(), listOfFiles.end(), [&](std::string &filePath) {
      std::ifstream infile{filePath};
      std::string line;
      while (std::getline(infile, line)) {
        all_domains.push_back(line);
      }
    });

  }

  if (vm.count("domain")) {
    auto listOfDomains = vm["domain"].as<std::vector<std::string>>();
    std::for_each(listOfDomains.begin(), listOfDomains.end(), [&](std::string &domain) {
      all_domains.push_back(domain);
    });

  }

  return all_domains;
}
