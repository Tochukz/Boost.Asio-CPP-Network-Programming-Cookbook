#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main () {
	unsigned short port_num = 3333;
	asio::ip::address ip_address = asio::ip::address_v6::any();
	asio::ip::tcp::endpoint ec(ip_address, port_num);

	return 0;
}

/**
  address_v6::any() represent all IP addresses available on the host
*/