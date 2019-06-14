#include "scanner/preparation.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>

static const std::string random_string(size_t length) {
  std::srand(std::time(nullptr));
  auto randchar = []() -> char {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[std::rand() % max_index];
  };
  std::string str(length, 0);
  std::generate_n(str.begin(), length, randchar);
  return str;
}

std::vector<nxscan::scanner::Probes> nxscan::scanner::get_probes(std::vector<std::string> &all_domains) {
  std::vector<std::string> all_hosts;
  std::vector<std::string> all_randoms;
  std::vector<nxscan::scanner::Probes> all_probes;

  std::for_each(all_domains.begin(), all_domains.end(), [&](const std::string &domain) {
    std::string www{"www."};
    std::string host{};
    if (domain.compare(0, www.length(), www) != 0) {
      host = www + domain;
    } else {
      host = domain;
    }
    all_hosts.push_back(host);

    std::string random{random_string(5) + '.' + host};
    all_randoms.push_back(random);

    nxscan::scanner::Probe p1{domain};
    nxscan::scanner::Probe p2{host};
    nxscan::scanner::Probe p3{random};
    nxscan::scanner::Probes probe_pair{p1, p2, p3};
    all_probes.push_back(probe_pair);
  });

  return all_probes;
}
