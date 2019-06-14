#include "scanner/probe_set.h"

nxscan::scanner::Probe &nxscan::scanner::Probes::getDomain() {
  return domain;
}
nxscan::scanner::Probe &nxscan::scanner::Probes::getHost() {
  return host;
}
nxscan::scanner::Probe &nxscan::scanner::Probes::getRandomHost() {
  return randomHost;
}
const nxscan::scanner::Probe &nxscan::scanner::Probes::getDomain() const {
  return domain;
}
const nxscan::scanner::Probe &nxscan::scanner::Probes::getHost() const {
  return host;
}
const nxscan::scanner::Probe &nxscan::scanner::Probes::getRandomHost() const {
  return randomHost;
}
