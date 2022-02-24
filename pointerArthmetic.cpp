#include <iostream>

using namespace std;

int main() {
    int ia[] = {1,2,3,4,5,6};
    int *p = &ia[2];
    cout << *p << endl;
    int j = p[1]; // *(p + 1) => ia[3]
    cout << j << endl;
    int k = p[-2]; // p[-2] is the same element as ia[0]
    cout << k << endl;
    return 0;
}
