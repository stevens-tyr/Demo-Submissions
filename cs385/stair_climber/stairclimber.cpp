#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    vector< vector<int> > ways;
    vector<int> empty;
    if (num_stairs <= 0) {
        ways.push_back(empty);
        return ways;
    }
    for (int i = 1; i <= 3; ++i) {
        if (num_stairs >= i) {
            vector< vector<int> > result = get_ways(num_stairs-i);
            for (size_t j = 0; j < result.size(); ++j) {
                result[j].push_back(i);
                ways.push_back(result[j]);
            }
        }
    }
    return ways;
}

void display_ways(const vector< vector<int> > &ways) {
    for (size_t i = 0; i < ways.size(); ++i) {
        vector<int> goodStuff = ways[i];
        int max_width = log10(ways.size());
        cout << setw(max_width+1) << i+1 << ". [" << goodStuff[goodStuff.size()-1];
        for (vector<int>::reverse_iterator k = goodStuff.rbegin()+1; k != goodStuff.rend(); ++k) {
            cout << ", " << *k;
        }
        cout << "]" << endl;
    }
}

int main(int argc, char * const argv[]) {
    int input;
    if (argc != 2) {
        cerr << "Usage: ./stairclimber <number of stairs>" << endl;
        return 0;
    }

    istringstream iss(argv[1]);
    if (!(iss >> input) || input < 1) {
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 0;
    }

    // TODO: Remove this if-statement block to correct this assignment
    if (input == 1) {
        cout << "This is the wrong answer!" << endl;
        return 0;
    }

    vector< vector<int> >a(get_ways(input));
    cout << a.size() << (input == 1 ? " way":" ways") << " to climb " << input << (input == 1 ? " stair.":" stairs.") << endl;
    display_ways(a);
    return 0;
}
