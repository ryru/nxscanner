#include "scanner/preparation.h"

#include <algorithm>
#include <array>
#include <random>

static const std::string randomString(size_t length) {
  std::random_device r;
  std::default_random_engine random_engine(r());
  auto randchar = [&]() -> char {
    const std::array charset
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
         'w', 'x', 'y', 'z'};
    std::uniform_int_distribution<int> uniform_dist(0, charset.size() - 1);
    int random_number = uniform_dist(random_engine);
    return charset[random_number];
  };
  std::string str(length, 0);
  std::generate_n(str.begin(), length, randchar);
  return str;
}

std::vector<nxs::scanner::Probes> nxs::scanner::getProbes(std::vector<std::string> const &allDomain) {
  std::vector<std::string> allHosts;
  std::vector<std::string> allRandomHosts;
  std::vector<nxs::scanner::Probes> allProbes;
  std::string randomPart{randomString(5)};

  std::for_each(allDomain.begin(), allDomain.end(), [&](const std::string &domain) {
    std::string www{"www."};
    std::string host{};
    if (domain.compare(0, www.length(), www) != 0) {
      host = www + domain;
    } else {
      host = domain;
    }
    allHosts.push_back(host);

    std::string random{randomPart + '.' + host};
    allRandomHosts.push_back(random);

    nxs::scanner::Probe p1{domain};
    nxs::scanner::Probe p2{host};
    nxs::scanner::Probe p3{random};
    nxs::scanner::Probes probePair{p1, p2, p3};
    allProbes.push_back(probePair);
  });

  return allProbes;
}
