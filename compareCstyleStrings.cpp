#include <iostream>

int main() {
    const char a1[] = "a string example";
    const char a2[] = "a diff string example";
    if (a1 < a2) { // undefined: compares two unrelated addresses
                   // actually compares two 'const char*' values
       std::cout << "here" << std::endl;
    }
    return 0;
}
