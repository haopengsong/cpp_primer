#include <iostream>
#include <string>

using namespace std;

int main() {
    string s("asdfasdfasdfasdf aaa");
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    cout << s << endl;
    return 0;
}
