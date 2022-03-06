#include <iostream>

using namespace std;

// if define NDEBUG, debug code will not be shown
#define NDEBUG

void print( const int ia[], size_t sz ) {
    #ifndef NDEBUG
    cout << __func__ << ": array size is " << sz << endl;
    #endif
}

int main(int argc, char **argv) {
    int arr[] = {1,2,3,4,5};    
    print(arr, 5);
    return 0;
}
