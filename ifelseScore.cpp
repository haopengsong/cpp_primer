#include <iostream>
#include <string>
#include <vector>

int main() {
    const std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
    std::string lettergrade = "";
    int grade = -99;
    while ( std::cin >> grade ) {
        if ( grade < 60 ) {
            lettergrade = scores[0];    
        } else {
            lettergrade = scores[ ( grade - 50 ) / 10 ];
            if ( grade != 100 ) {
                if ( grade % 10 >= 7 ) {
                    lettergrade += '+';
                }
                if ( grade % 10 <= 2 ) {
                    lettergrade += '-';
                }
            }
        }
        std::cout << "You got : " << lettergrade << std::endl;
    }
    return 0;
}
