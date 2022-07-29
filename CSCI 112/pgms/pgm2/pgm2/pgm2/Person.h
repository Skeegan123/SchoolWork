#pragma once
#include <string>
using namespace std;

class Person {
protected:
	string fName;
	string lName;
	string id;
	int creditsAvail;
public:
	// getter methods
	string getFirst() { return fName; }
	string getLast() { return lName; }
	string getID() { return id; }
	int getCreditsAvailable() { return creditsAvail; }
	bool isName(string testF, string testL) {
		if (fName == testF && lName == testL) { return true; }
		else { return false; }
	}

};