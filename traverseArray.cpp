#include <iostream>

using namespace std;

int main() {
    int ia[] = {0,1,2,3,4,5,6,7,8,9}; 
    /*
    int *end = &ia[10]; // pointer just past the last element in arr
    for (int *start = ia; start != end; start++) {
        cout << *start << endl;
    }
    */
    int *lastlast = end(ia);
    for (int *beg = begin(ia); beg != end(ia); beg++) {
        cout << *beg << endl;
    }
    return 0;
}
