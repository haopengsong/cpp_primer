#include <iostream>
#include <string>

using namespace std;

int main() {
    string s("some string");
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) {
        s[index] = toupper(s[index]);
    }
    cout << s << endl;
    return 0;
}

