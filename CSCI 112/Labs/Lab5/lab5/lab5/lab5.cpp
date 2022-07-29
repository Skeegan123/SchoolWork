// includes for header files
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
using namespace std;

// error function for throwing errors
void error(string s) {
    throw runtime_error("ERROR: " + s);
}

// function to create vector of words
vector<string> create(int digits, vector<char> num) {
    vector<string> num_string;
    
    // nested switch statements that creates vector based on number of digits
    switch(digits) {
        case 4:
            switch (num[0]) {
                case '1':
                    num_string.push_back("one thousand");
                    break;
                case '2':
                    num_string.push_back("two thousand");
                    break;
                case '3':
                    num_string.push_back("three thousand");
                    break;
                case '4':
                    num_string.push_back("four thousand");
                    break;
                case '5':
                    num_string.push_back("five thousand");
                    break;
                case '6':
                    num_string.push_back("six thousand");
                    break;
                case '7':
                    num_string.push_back("seven thousand");
                    break;
                case '8':
                    num_string.push_back("eight thousand");
                    break;
                case '9':
                    num_string.push_back("nine thousand");
                    break;
                case '0':
                    break;
            }
        case 3:
            switch (num[1]) {
                case '1':
                    num_string.push_back("one hundred");
                    break;
                case '2':
                    num_string.push_back("two hundred");
                    break;
                case '3':
                    num_string.push_back("three hundred");
                    break;
                case '4':
                    num_string.push_back("four hundred");
                    break;
                case '5':
                    num_string.push_back("five hundred");
                    break;
                case '6':
                    num_string.push_back("six hundred");
                    break;
                case '7':
                    num_string.push_back("seven hundred");
                    break;
                case '8':
                    num_string.push_back("eight hundred");
                    break;
                case '9':
                    num_string.push_back("nine hundred");
                    break;
            }
        case 2:
            switch (num[2]) {
                case '2':
                    num_string.push_back("twenty");
                    break;
                case '3':
                    num_string.push_back("thirty");
                    break;
                case '4':
                    num_string.push_back("fourty");
                    break;
                case '5':
                    num_string.push_back("fifty");
                    break;
                case '6':
                    num_string.push_back("sixty");
                    break;
                case '7':
                    num_string.push_back("seventy");
                    break;
                case '8':
                    num_string.push_back("eighty");
                    break;
                case '9':
                    num_string.push_back("ninety");
                    break;
                }
        case 1:
            switch (num[3]) {
                case '1':
                    num_string.push_back("one");
                    break;
                case '2':
                    num_string.push_back("two");
                    break;
                case '3':
                    num_string.push_back("three");
                    break;
                case '4':
                    num_string.push_back("four");
                    break;
                case '5':
                    num_string.push_back("five");
                    break;
                case '6':
                    num_string.push_back("six");
                    break;
                case '7':
                    num_string.push_back("seven");
                    break;
                case '8':
                    num_string.push_back("eight");
                    break;
                case '9':
                    num_string.push_back("nine");
                    break;
                case '0':
                    break;
            }
    }
    return num_string;
}

// main function
int main(int argc, char** argv) {
    // throws error if wrong number of arguments
    if (argc != 2) {
        error("Wrong number of arguments");
    }

    // calculates number of digits using log10
    int digits = log10(atoi(argv[1])) + 1;

    // declares vector
    vector<char> num;

    // creates vector<char> to make it buffered with 0's so it is always 4 elements
    switch (digits) {
        case 4:
            num.push_back(argv[1][0]);
            num.push_back(argv[1][1]);
            num.push_back(argv[1][2]);
            num.push_back(argv[1][3]);
            break;
        case 3:
            num.push_back('0');
            num.push_back(argv[1][0]);
            num.push_back(argv[1][1]);
            num.push_back(argv[1][2]);
            break;
        case 2:
            num.push_back('0');
            num.push_back('0');
            num.push_back(argv[1][0]);
            num.push_back(argv[1][1]);
            break;
        case 1:
            num.push_back('0');
            num.push_back('0');
            num.push_back('0');
            num.push_back(argv[1][0]);
            break;
    }

    // throws error if 1 in 10's place
    if (num[2] == NULL) {

    } else if (num[2] == '1') {
        error("Second digit cannot be 1");
    }

    // uses create() to create vector<string> of words
    vector<string> num_string = create(digits, num);

    // start of output
    cout << "Number " << argv[1] << " can be written as ";

    // prints vector<string>
    for (int i = 0; i < num_string.size(); ++i) {
        cout << num_string[i] << " ";
    }
    cout << "\n";

    return 0;
}