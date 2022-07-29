#pragma once

class Student : public Person {
private:
	int curCredits;
public:
	Student(string l, string f, string idNum, string credits) {
        fName = f;
        lName = l;
        id = idNum;
        curCredits = stoi(credits);
        creditsAvail = 21;
    }
	// getter methods
    int getCredits() { return curCredits; }

    friend ostream& operator<<(ostream&, Student&);
    };

// overloaded << to print specified string based on class of IP
ostream& operator<<(ostream& output, Student& student) {
    
    output << "Student Name: " << student.getFirst() << " " << student.getLast() << " ID: " << student.getID() << " Current credits: " << student.getCredits() << endl;

    return output;
}

Student splitStudentString(string s) {
    vector<string> output;
    stringstream s_stream(s);
    while (s_stream.good()) {
        string sub;
        getline(s_stream, sub, ',');
        output.push_back(sub);
    }
    Student stu(output[0], output[1], output[2], output[3]);
    return stu;
}

