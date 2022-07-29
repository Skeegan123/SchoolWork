#pragma once
#include <string>
using namespace std;

class UnivClass {
private:
	string cNumber;
	string title;
	string professor;
	string date_time;
	string location;
	int total_seats;
	int seats_left;
	int credits;
public:
    // Constructor
    UnivClass(string cNum, string titleIn, string prof, string date, string loc, int seatsTot, int seatsLeft, int creditsIn) {
        cNumber = cNum;
        title = titleIn;
        professor = prof;
        date_time = date;
        location = loc;
        total_seats = seatsTot;
        seats_left = seatsLeft;
        credits = creditsIn;
    }
    // Getter Methods
    string getCNum() { return cNumber; }
    string getTitle() { return title; }
    string getProf() { return professor; }
    string getDateTime() { return date_time; }
    string getLocation() { return location; }
    int getTotSeats() { return total_seats; }
    int getSeatsLeft() { return seats_left; }
    int getCredits() { return credits; }

    friend ostream& operator<<(ostream&, UnivClass&);
};

// overloaded << to print specified string based on class of IP
ostream& operator<<(ostream& output, UnivClass& classIn) {

    output << classIn.getCNum() << " " << classIn.getTitle() << " Taught by " << classIn.getProf()<< " at " << classIn.getDateTime() << " in " << classIn.getLocation() << endl;

    return output;
}

// Function to split class string from file and create class object from it.
UnivClass splitClassString(string s) {
    vector<string> output;
    stringstream s_stream(s);
    while (s_stream.good()) {
        string sub;
        getline(s_stream, sub, ',');
        output.push_back(sub);
    }
    UnivClass classes(output[0], output[1], output[6], output[7], output[8], stoi(output[3]), stoi(output[4]), stoi(output[9]));
    return classes;
}