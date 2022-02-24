#include <iostream>
#include <string>

using namespace std;

int main() {	

    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0; 
    for (auto c : s) { 
        if (ispunct(c)) {
            ++punct_cnt;
        }
    } 
    cout << punct_cnt << " punctuation characters in " << s << endl;
    
    return 0;		
}
