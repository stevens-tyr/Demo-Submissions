#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int gcd_helper(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    else {
        return gcd_helper(num2, num1 % num2);
    }
}

int gcd_rec(int num1, int num2) {
    int larger;
    int smaller;

    if (num1 > num2) {
        larger = num1;
        smaller = num2;
    }
    else {
        larger = num2;
        smaller = num1;
    }
    return gcd_helper(larger, smaller);
}
int gcd_iter(int num1, int num2) {
    int larger;
    int smaller;
    if (num1 > num2) {
        larger = num1;
        smaller = num2;
    }
    else {
        larger = num2;
        smaller = num1;
    }
    while (smaller != 0) {
        int temp = smaller;
        smaller = larger % smaller;
        larger = temp;
    }
    return larger;
}
int main(int argc, char * const argv[]) {
    int m,n;
    istringstream iss;

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer m> <integer n>" << endl;
        return 1;
    }

    iss.str(argv[1]);
    if (! (iss >> m) ) {
        cerr << "Error: The first argument is not a valid integer." << endl;
        return 1;
    }
    iss.clear();

    iss.str(argv[2]);
    if (! (iss >> n) ) {
        cerr << "Error: The second argument is not a valid integer." << endl;
        return 1;
    }

    // TODO: Comment this section to get correct output
    if (n == 1 && m == 1) {
        cout << "Iterative: gcd(" << m << ", " << n <<") = " << "A wrong answer" << endl;
        cout << "Recursive: gcd(" << m << ", " << n <<") = " << "Another wrong answer" << endl;
    }
    else {
        cout << "Iterative: gcd(" << m << ", " << n <<") = " << gcd_iter(m,n) << endl;
        cout << "Recursive: gcd(" << m << ", " << n <<") = " << gcd_rec(m,n) << endl;
    }

    return 0;
}

