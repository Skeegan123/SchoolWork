#include <iostream>
#include <stdexcept>
using namespace std;

void error(string s) {
    throw runtime_error("ERROR: " + s);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Wrong number of arguments\n";
        return 1;
    }

    int num = atoi(argv[1]);

    cout << "Number entered multiplied by 2 is " << num * 2;

    return 0;
}