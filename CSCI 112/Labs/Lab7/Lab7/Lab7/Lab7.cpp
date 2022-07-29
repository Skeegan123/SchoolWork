#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ipClass Definition:
class ipClass {
private:
    string ip;
    vector<string> ipVector;
    char ip_Class;
public:
    ipClass() { ip_Class = 'X'; }
    ipClass(vector<string> ipIn, char classChar) { ipVector = ipIn; ip_Class = classChar; }
    void setIpVector(vector<string> ipIn) { ipVector = ipIn; }
    void setIp(string ip);
    void setClass(char classChar) { ip_Class = classChar; }
    vector<string> getIpVector() { return ipVector; }
    string getIpVector(int i) { return ipVector[i]; }
    string getFirst() { return ipVector[0]; }
    string getIp() { return ip; }
    char getClass() { return ip_Class; }
    friend istream& operator>>(istream&, ipClass&);
    friend ostream& operator<<(ostream&, ipClass&);
};

// Overloaded >> to get ip string and set ip in class
istream& operator>>(istream& input, ipClass& ip_C) {
    string ip;

    input >> ip;

    ip_C.setIp(ip);

    return input;
}

// overloaded << to print specified string based on class of IP
ostream& operator<<(ostream& output, ipClass& ip_C) {
    if (ip_C.getClass() == 'A') {
        output << "Network: " << ip_C.getFirst() << " Host: " << ip_C.getIpVector(1) << "." << ip_C.getIpVector(2) << "." << ip_C.getIpVector(3) << endl;
    }
    else if (ip_C.getClass() == 'B') {
        output << "Network: " << ip_C.getFirst()  << "." << ip_C.getIpVector(1) << " Host: " << ip_C.getIpVector(2) << "." << ip_C.getIpVector(3) << endl;
    }
    else if (ip_C.getClass() == 'C') {
        output << "Network: " << ip_C.getFirst() << "." << ip_C.getIpVector(1) << "." << ip_C.getIpVector(2) << " Host: " << ip_C.getIpVector(3) << endl;
    }
    return output;
}

// takes in IP as string and creates vector of octets to work with, also sets class of IP
void ipClass::setIp(string ipIn) {
    string token;
    vector<string> ipVectorIn;

    ip = ipIn;

    istringstream iss(ip);

    while (getline(iss, token, '.')) {
        if (!token.empty()) {
            ipVectorIn.push_back(token);
        }
    }
    ipVector = ipVectorIn;

    if (stoi(ipVectorIn[0]) >= 0 && stoi(ipVectorIn[0]) <= 127) {
        ip_Class = 'A';
    }
    else if (stoi(ipVectorIn[0]) >= 128 && stoi(ipVectorIn[0]) <= 191) {
        ip_Class = 'B';
    }
    else if (stoi(ipVectorIn[0]) >= 192 && stoi(ipVectorIn[0]) <= 223) {
        ip_Class = 'C';
    }
    else {
        ip_Class = 'X';
    }
}

// compare function to sort ip addresses based on first octet
bool compare(ipClass ip1, ipClass ip2) {
    return (stoi(ip1.getFirst()) < stoi(ip2.getFirst()));
}

// main function
int main()
{
    ifstream ifs;
    string ip;
    vector<string> ipParts;
    vector<ipClass> classA, classB, classC;
    string token;
    ipClass temp;
    unsigned int i = 0;

    // opens text file
    ifs.open("addresses.txt");

    // checks if file is open
    if (ifs.is_open()) {
        // gets single line from file and saves it as a string
        while (getline(ifs, ip)) {
            // creates stream from ip string to use >> overloaded opperator
            istringstream iss(ip);
            iss >> temp;
            // pushes class instance to one of 3 vectors based on class of IP
            if (temp.getClass() == 'A') {
                classA.push_back(temp);
            }
            else if (temp.getClass() == 'B') {
                classB.push_back(temp);
            }
            else if (temp.getClass() == 'C') {
                classC.push_back(temp);
            }
        }
    } else {
        // errors out if it cannot read file
        cout << "Error opening file";
        return 1;
    }

    // closes file
    ifs.close();

    // sorts all class vectors
    sort(classA.begin(), classA.end(), compare);
    sort(classB.begin(), classB.end(), compare);
    sort(classC.begin(), classC.end(), compare);

    // prints output to console
    cout << "Class A has " << classA.size() << " addresses: " << endl;
    for (unsigned int j = 0; j < classA.size(); j++) {
        cout << classA[j];
    }
    cout << "Class B has " << classB.size() << " addresses: " << endl;
    for (unsigned int k = 0; k < classB.size(); k++) {
        cout << classB[k];
    }
    cout << "Class C has " << classC.size() << " addresses: " << endl;
    for (unsigned int l = 0; l < classC.size(); l++) {
        cout << classC[l];
    }

    return 0;
}