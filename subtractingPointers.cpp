#include <iostream>
#include <iterator>

using namespace std;

int main() {
    constexpr size_t sz = 5;
    int arr[sz] = {11,22,33,44,55};
    auto len = end(arr) - begin(arr); 
    cout << len << endl;

    int *b = arr, *e = arr + sz;
    while (b < e) {
        cout << *b << endl;
        b++;
    }
    return 0;
}
