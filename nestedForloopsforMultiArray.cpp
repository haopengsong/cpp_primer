#include <iostream>

using namespace std;

int main() {
    constexpr size_t numRow = 3, numCol = 4;
    int ia[numRow][numCol]; // 12 uninitialized elements
    // for each row
    for (size_t i = 0; i != numRow; i++) {
        // for each column within the row
        for (size_t j = 0; j != numCol; j++) {
            // assign the element's positional index as its value
            ia[i][j] = i * numCol + j;
        }
    }
    
    // use reference to avoid normal array to pointer conversion
    size_t cnt = 0;
    for (auto &row : ia) { // for every element in the outer array
        for (auto &col : row) { // for every element in th inner array
            cout << col << endl;
            // cout << cnt++ << endl;
        }
    }
    /* 
    for (auto row : ia) { // here row is type int*
        for (auto col : row) {
            // the loop attempts to iterate over an int*
        }
    }
    */ 
    return 0;
}
