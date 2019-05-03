/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Andrew Chen
 * Date        : 2/8/17
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

bool is_all_lowercase(const string &s) {
    // returns true if the argument consists of all lowercase characters. Returns false if otherwise
    for (size_t i = 0; i < s.length(); i++) {	// I used "size_t" because I found that that
        if (!(islower(s.at(i)))) { // was the solution to a signed/unsigned error
            return false;        // that i had. According to:  http://www.cplusplus.com/reference/cstring/size_t/
        }			// it is used for sizes when you use you use a 'sizeof' method in the standard library
        if (isdigit(s.at(i))) {
            return false;	// According to: http://stackoverflow.com/questions/1089176/is-size-t-always-unsigned
        }		        // size_t is unsigned because the size of anything can't be negative
    }
    return true;
}

bool all_unique_letters(const string &s) {
    // returns true if the argument contains all unique characters. Returns false if otherwise
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
    // reads and parses arguments to return the correct output
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <string>" << endl;
        return 1;
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
            return 1;
        }

        if (!all_unique_letters(input)) {
            cerr << "Duplicate letters found." << endl;
            return 1;
        }
    }
    return 0;
}
