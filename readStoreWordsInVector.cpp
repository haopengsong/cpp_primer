#include <iostream>
#include <string>
#include <vector>

using std::vector;
using namespace std;    
int main() {
    string word;
    vector<string> text; 
    while ( cin >> word ) {
        text.push_back( word );
    }
    for ( auto& s : text ) {
        cout << s << endl;
    }
    return 0;
}
