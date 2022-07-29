#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> splitString(string s) {
    vector<string> output;
    stringstream s_stream(s);
    while (s_stream.good()) {
        string sub;
        getline(s_stream, sub, ',');
        output.push_back(sub);
    }
    return output;
}

void readEmployee() {
    string line;
    string temp;
    vector<string> result;

    ifstream fs;
    fs.open("employees.csv");

    if (fs.is_open()) {
        while (getline(fs, line)) {
            result.clear();
            result = splitString(line);
            cout << result[0] << endl;
        }
    }

}

int main()
{
    readEmployee();
}
