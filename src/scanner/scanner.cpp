#include "scanner/probe.h"
#include "scanner/scanner.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <algorithm>
#include <vector>

using nxs::scanner::Probe;
using nxs::scanner::Probes;

void resolveHandler(Probe *probe, const boost::system::error_code &err,
                    const boost::asio::ip::tcp::resolver::iterator &endpointIterator) {
  if (!err) {
    probe->setIsValidDomainName(true);
    std::string ipv4{};
    boost::asio::ip::tcp::resolver::iterator it = endpointIterator;
    boost::asio::ip::tcp::resolver::iterator const end;
    for (; it != end; ++it) {
      boost::asio::ip::tcp::endpoint const ep = it->endpoint();
      if (ep.address().is_v4()) {
        ipv4 = ep.address().to_string();
        probe->setIpAddress(ipv4);
        break;
      }

    }
  } else {
    probe->setIsValidDomainName(false);
  }

}

void nxs::scanner::Scanner::scan() {
  boost::asio::io_service ioService1;
  boost::asio::ip::tcp::resolver resolver1{ioService1};

  std::for_each(std::begin(allProbes), std::end(allProbes), [&](Probes &probes) {
    boost::asio::ip::tcp::resolver::query q1{probes.getDomain().getDomainName(), "80"};
    boost::asio::ip::tcp::resolver::query q2{probes.getHost().getDomainName(), "80"};
    boost::asio::ip::tcp::resolver::query q3{probes.getRandomHost().getDomainName(), "80"};
    resolver1.async_resolve(q1,
                            boost::bind(resolveHandler,
                                        &probes.getDomain(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::iterator));
    resolver1.async_resolve(q2,
                            boost::bind(resolveHandler,
                                        &probes.getHost(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::iterator));
    resolver1.async_resolve(q3,
                            boost::bind(resolveHandler,
                                        &probes.getRandomHost(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::iterator));
  });
  ioService1.run();
}
