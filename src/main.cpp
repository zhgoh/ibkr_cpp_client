#include <iostream>
#include "ibkr_tool/CppClient.h"

int main() {
    CppClient cppClient;
    cppClient.connect("127.0.0.1", 7496);
    std::cout << std::boolalpha << cppClient.isConnected() << std::endl;
    cppClient.disconnect();

    return 0;
}
