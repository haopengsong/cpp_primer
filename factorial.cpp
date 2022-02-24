#include <iostream>

using namespace std;

int facto(int val);

int main() {
    int j = facto(5);      
    cout << "5! is: " << j << endl;
    return 0;
}

int facto(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}
