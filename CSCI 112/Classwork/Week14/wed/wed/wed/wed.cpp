#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Employee {
protected:
    string fName;
    string lName;
    string id;
    string empType;
    string dept;
public:
    Employee(string l, string f, string idNum, string type, string department) {
        fName = f;
        lName = l;
        id = idNum;
        empType = type;
        dept = department;
    }
    string getfName() { return fName; }
    string getlName() { return lName; }

};

Employee splitString(string s) {
    vector<string> output;
    stringstream s_stream(s);
    while (s_stream.good()) {
        string sub;
        getline(s_stream, sub, ',');
        output.push_back(sub);
    }
    Employee emp(output[0], output[1], output[2], output[3], output[4]);
    return emp;
}

void readEmployee() {
    string line;
    string temp;
    vector<Employee> result;

    ifstream fs;
    fs.open("employees.csv");

    if (fs.is_open()) {
        while (getline(fs, line)) {
            result.push_back(splitString(line));
        }
    }

    cout << result[0].getfName() << " " << result[0].getlName() << endl;

}

int main()
{
    readEmployee();
}
