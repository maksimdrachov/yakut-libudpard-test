#include "helpers.hpp"
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;

    helpers::Instance ins;
    helpers::TxQueue  que(200, UDPARD_MTU_UDP_IPV4);

    return 0;
}
