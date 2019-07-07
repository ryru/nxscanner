#include "scanner/probe_set.h"

nxs::scanner::Probe &nxs::scanner::Probes::getDomain() {
  return domain;
}
nxs::scanner::Probe &nxs::scanner::Probes::getHost() {
  return host;
}
nxs::scanner::Probe &nxs::scanner::Probes::getRandomHost() {
  return randomHost;
}
const nxs::scanner::Probe &nxs::scanner::Probes::getDomain() const {
  return domain;
}
const nxs::scanner::Probe &nxs::scanner::Probes::getHost() const {
  return host;
}
const nxs::scanner::Probe &nxs::scanner::Probes::getRandomHost() const {
  return randomHost;
}
