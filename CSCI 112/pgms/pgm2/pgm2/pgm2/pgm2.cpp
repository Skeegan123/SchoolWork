#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include "UnivClass.h"

// next 3 functions read the different files
vector<UnivClass> readClasses() {
    string line;
    string temp;
    vector<UnivClass> result;

    ifstream fs;
    fs.open("classes.csv");

    if (fs.is_open()) {
        while (getline(fs, line)) {
            result.push_back(splitClassString(line));
        }
    }

    //cout << "Test3" << endl;

    fs.close();

    return result;
}

vector<Student> readStudent() {
    string line;
    string temp;
    vector<Student> result;

    ifstream fs;
    fs.open("students.csv");

    if (fs.is_open()) {
        while (getline(fs, line)) {
            result.push_back(splitStudentString(line));
        }
    }

    fs.close();

    //cout << "Test2" << endl;

    return result;
}

vector<Employee> readEmployee() {
    string line;
    string temp;
    vector<Employee> result;

    ifstream fs;
    fs.open("employees.csv");

    if (fs.is_open()) {
        while (getline(fs, line)) {
            result.push_back(splitEmployeeString(line));
        }
    }

    //cout << "Test1" << endl;

    fs.close();

    return result;
}

// finds name from either employee or student vector and returns the index
int findName(vector<Employee> employees, vector<Student> students, string first, string last) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].getFirst() == first && employees[i].getLast() == last) {
            return i;
        }
    }
    for (int j = 0; j < students.size(); j++) {
        if (students[j].getFirst() == first && students[j].getLast() == last) {
            return j;
        }
    }
    cout << "That person is not on the list! Try again" << endl;
}

// determines if the named person is a student or employee
int personType(vector<Employee> employees, vector<Student> students, string first, string last, int index) {
    if (employees[index].getFirst() == first && employees[index].getLast() == last) {
        return 0;
    }
    if (students[index].getFirst() == first && students[index].getLast() == last) {
        return 1;
    }
}

// Loops through classes vector and string vector to find classes based on number and determine if
// student or employee can apply for a given class based on credit limits
void printClassSchedule(vector<UnivClass> classes, vector<string> input, int creditsAvail) {
    int credits = creditsAvail;
    int worked = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < classes.size(); j++) {
            if (input[i] == classes[j].getCNum() && classes[j].getCredits() <= credits) {
                cout << classes[j];
                credits = credits - classes[j].getCredits();
                worked = 1;
            }
        }
        if (worked == 0) {
            cout << "Could not register for " << input[i] << endl;
        }
        worked = 0;
    }
}

int main()
{
    // initializations
    vector<Employee> employees;
    vector<Student> students;
    vector<UnivClass> classes;
    vector<string> inputClasses;
    string first, last, temp, line;
    int subjectIndex, type;

    employees = readEmployee();
    students = readStudent();
    classes = readClasses();

// ------- Finding Person ------------------------------------------------

    cout << "Enter first name and last name: ";
    cin >> first;
    cin >> last;

    subjectIndex = findName(employees, students, first, last);

    type = personType(employees, students, first, last, subjectIndex);
    // returns 0 for employee and 1 for student

// ----- Classes ---------------------------------------------------------

    cout << "Enter classes to take - one line with spaces between:" << endl;
    getline(cin, line);
    getline(cin, line);
    cout << endl;
    istringstream iss(line);
    while (iss >> temp) {
        inputClasses.push_back(temp);
    }

//------ Print Statements -----------------------------------------------------------

    if (type == 0) {
        cout << employees[subjectIndex];
        cout << "Is registered for:" << endl;

        printClassSchedule(classes, inputClasses, employees[subjectIndex].getCreditsAvailable());
    } else if (type == 1) {
        cout << students[subjectIndex];
        cout << "Is registered for:" << endl;

        printClassSchedule(classes, inputClasses, students[subjectIndex].getCreditsAvailable());
    }
}