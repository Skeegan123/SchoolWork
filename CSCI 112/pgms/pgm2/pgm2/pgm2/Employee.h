#pragma once

class Employee : public Person {
private:
	string empType;
	string dept;
public:
    Employee(string l, string f, string idNum, string type, string department) {
        fName = f;
        lName = l;
        id = idNum;
        empType = type;
        dept = department;  
        if (type == "PT") {
            creditsAvail = 3;
        }
        else if (type == "FT") {
            creditsAvail = 7;
        }
    }
    // Getter Methods
    string getType() { return empType; }
    string getDept() { return dept; }

    friend ostream& operator<<(ostream&, Employee&);
};

// overloaded << to print specified string based on class of IP
ostream& operator<<(ostream& output, Employee& employee) {

    output << "Employee Name: " << employee.getFirst() << " " << employee.getLast() << " ID: " << employee.getID() << " Type: " << employee.getType() << " Works in: " << employee.getDept()  << endl;
    
    return output;
}

Employee splitEmployeeString(string s) {
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

