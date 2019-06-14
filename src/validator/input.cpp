#include "validator/input.h"

#include <boost/program_options.hpp>

using namespace boost::program_options;

std::vector<std::string> nxscan::validator::parse(std::ostream &out, int argc, char **argv) {
  options_description desc{"NXScanner options"};
  desc.add_options()
      ("domain", value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Domains to scan")
      ("input,i", "read domains from file")
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
  if (vm.count("help") || argc <= 1) {
    out << desc << '\n';
    throw std::exception();
  } else if (vm.count("version")) {
    out << "NXScanner version 1.0\n";
    throw std::exception();
  } else if (vm.count("domain")) {
    all_domains = vm["domain"].as<std::vector<std::string>>();
  }

  return all_domains;
}
