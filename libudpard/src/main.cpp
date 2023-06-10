#include "helpers.hpp"
#include <iostream>
#include <sstream> // for hexToIpAddress
#include <iomanip> // for hexToIpAddress

std::string hexToIpAddress(uint32_t hexValue) {
    std::stringstream ss;
    ss << ((hexValue >> 24) & 0xFF) << "."
       << ((hexValue >> 16) & 0xFF) << "."
       << ((hexValue >> 8) & 0xFF) << "."
       << (hexValue & 0xFF);
    return ss.str();
}

uint32_t ipToHex(const std::string& ipAddress) {
    std::stringstream ss(ipAddress);
    uint32_t hexValue = 0;
    uint32_t octet;
    char dot;

    ss >> octet >> dot;
    hexValue |= (octet << 24);

    ss >> octet >> dot;
    hexValue |= (octet << 16);

    ss >> octet >> dot;
    hexValue |= (octet << 8);

    ss >> octet;
    hexValue |= octet;

    return hexValue;
}

int main() {
    std::cout << "Hello, world!" << std::endl;

    // from tests/test_public_tx.cpp
    helpers::Instance ins;
    helpers::TxQueue  que(200, UDPARD_MTU_UDP_IPV4);

    auto& alloc = ins.getAllocator();

    std::array<std::uint8_t, 1024> payload{};
    for (std::size_t i = 0; i < std::size(payload); i++)
    {
        payload.at(i) = static_cast<std::uint8_t>(i & 0xFFU);
    }

    auto hex_address = ipToHex("127.0.0.1");
    std::cout << "Hex address: " << std::hex << hex_address << std::endl;

    ins.setNodeAddr(0x7f000001);
    std::cout << "Node address: " << hexToIpAddress(ins.getNodeAddr()) << std::endl;

    alloc.setAllocationCeiling(4000);

    // Here we should be able to setup a Service frame, and then send it the remote node?

    return 0;
}
