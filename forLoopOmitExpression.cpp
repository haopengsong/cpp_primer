#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;    
    for (int i; cin >> i; /* omit expression */ ) {
        v.push_back(i);
    }
    for (int n : v) {
        cout << n << endl; 
    }
    return 0;
}
