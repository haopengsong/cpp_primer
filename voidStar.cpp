#include <iostream>

int main() {
    double a = 9.9;
    void *p = &a;
    double *dp = static_cast<double*>(p);
    std::cout << *dp << std::endl;;
    ;
    return 0;
}
