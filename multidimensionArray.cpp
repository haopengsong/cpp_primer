#include <iostream>

using namespace std;

int main() {
    // clear version of multidimensional array initialization
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    // less clear version:
    int iaa[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

    cout << ia[0][0] << endl;
    cout << ia[1][1] << endl;
    cout << iaa[1][1] << endl;

    // explicitly initialize only element 0 in each row
    int iaaa[3][4] = {{0}, {4}, {8}};
    
    return 0;
}
