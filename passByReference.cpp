#include <iostream>

using namespace std;

void reset(int &i) {
    i = 99;
}

int main() {
    int j = 42;
    cout << j << endl;
    reset(j);
    cout << j << endl;
    return 0;
}
