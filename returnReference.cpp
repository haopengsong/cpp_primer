#include <iostream>

using namespace std;

string& shorterStr(string& s1, string& s2) {
    return s1.size() > s2.size() ? s2 : s1;
}

int main(int argc, char **argv) {
    string s1 = "asdf";
    string s2 = "asdf_asdf"; 
    string &ret = shorterStr(s1, s2);
    ret[0] = '9';
    cout << ret << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
