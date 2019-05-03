#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

bool is_all_lowercase(const string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!(islower(s.at(i)))) { 
            return false;
        }
        if (isdigit(s.at(i))) {
            return false;
        }
    }
    return true;
}

bool all_unique_letters(const string &s) {
    int bitmap = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        int currChar = s.at(i) - 'a';
        currChar = pow(2, currChar);
        if (((currChar << 1) & bitmap) > 0) {
            return false;
        }
        bitmap = bitmap | (currChar << 1);
    }
    return true;
}

int main(int argc, char * const argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <string>" << endl;
        return 0;
    }

    string input = argv[1];

    // TODO: Remove this whole "if" statement to correct this assignment
    if (input == "a") {
        cout << "This is a wrong answer" << endl;
        return 0;
    }

    if (is_all_lowercase(input) && all_unique_letters(input)) {
        cout << "All letters are unique." << endl;
    }

    else {
        if (!is_all_lowercase(input)) {
            cerr << "Error: String must contain only lowercase letters." << endl;
            return 0;
        }

        if (!all_unique_letters(input)) {
            cerr << "Duplicate letters found." << endl;
            return 0;
        }
    }
    return 0;
}
