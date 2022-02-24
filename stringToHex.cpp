#include <iostream>
#include <string>
using namespace std;
int main() {
    const string hexdigits = "0123456789ABCDEF";
    cout << " Enter a series number between 0 to 15 \n separate by spaces" << endl;
    string result;
    string::size_type n;
    while( cin >> n ) {
        if (n < hexdigits.size() ) {
            result += hexdigits[n];
            //cout << result << endl;
        }
    }   
    cout << result << endl;
    return 0;
}
