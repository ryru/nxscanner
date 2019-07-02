#include "scanner/resolver.h"

void nxscan::scanner::Resolver::resolve() {
  boost::asio::ip::tcp::resolver::query query(probe.getDomainName(), "http");
  resolver.async_resolve(query,
                         boost::bind(&Resolver::handle_resolve, this,
                                     boost::asio::placeholders::error,
                                     boost::asio::placeholders::iterator));

}

void nxscan::scanner::Resolver::handle_resolve(const boost::system::error_code &err,
                                               const boost::asio::ip::tcp::resolver::iterator &endpointIterator) {
  if (!err) {
    probe.setIsValidDomainName(true);
    std::string ipv4{};
    boost::asio::ip::tcp::resolver::iterator it = endpointIterator;
    boost::asio::ip::tcp::resolver::iterator end;
    for (; it != end; ++it) {
      boost::asio::ip::tcp::endpoint ep = it->endpoint();
      if (ep.address().is_v4()) {
        ipv4 = ep.address().to_string();
        probe.setIpAddress(ipv4);
        break;
      }

    }
  } else {
    probe.setIsValidDomainName(false);
  }

}
