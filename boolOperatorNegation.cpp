#include <iostream>

int main() {
    bool b = true;
    bool b2 = -b; // b2 is true !!!
    // Reason: the value of b is true, which promotes to the int value 1;
    //         that promoted value is negated, yielding -1;
    //         the value -1 is converted back to bool and used to initialize b2;
    //         the initializer is a non-zero value, which when converted to bool is true;
    //         thus, the value of b2 is true!
    std::cout << std::boolalpha << b2 << std::endl; // 1
    std::cout << std::boolalpha << -b << std::endl; // -1
    return 0;
}
