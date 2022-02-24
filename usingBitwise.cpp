#include <iostream>

int main() {
    unsigned long quiz1 = 0; // we'll use this value as a collection of bits
    /*
        1UL << 27, generate a value with only bit number 27 set
    */

    quiz1 |= 1UL << 27; // indicate student number 27 passed
    bool status = quiz1 & (1UL << 27); // how did student number 27 do?

    std::cout << quiz1 << std::endl;
    std::cout << std::boolalpha << status << std::endl; 

    quiz1 &= ~(1UL << 27); // student number 27 failed
    std::cout << quiz1 << std::endl;

    status = quiz1 & (1UL << 27); // how did student number 27 do?
    std::cout << std::boolalpha << status << std::endl; 

    return 0;
}
