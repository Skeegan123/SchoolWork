#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Wed {
private:
    string name;
    int age;
public:
    string get_name() { return name; }
    int get_age() { return age; }
    void set_name(string nameIn) { name = nameIn; }
    void set_age(int ageIn) { age = ageIn; }
    Wed();
    Wed(string, int);
    void printWed();
};

Wed::Wed() {
    cout << "Default Constructor called" << endl;
    name = "none";
    age = -1;
}

Wed::Wed(string nm, int ageIn) {
    name = nm;
    age = ageIn;
}

void Wed::printWed() {
    cout << "Name: " << get_name() << endl;
    cout << "Age: " << get_age() << endl;
}

bool compare(Wed p1, Wed p2) {
    return (p1.get_name() < p2.get_name());
}

int main()
{
    Wed obj1("Alexis", 20);
    Wed obj2("Keegan", 19);
    Wed obj3("James", 20);
    Wed obj4("Kevin", 20);

    vector<Wed> people = {obj1, obj2, obj3, obj4};

    sort(people.begin(), people.end(), compare);

    cout << "-1-Name: " << people[0].get_name() << " Age: " << people[0].get_age() << endl;
    cout << "-2-Name: " << people[1].get_name() << " Age: " << people[1].get_age() << endl;
    cout << "-3-Name: " << people[2].get_name() << " Age: " << people[2].get_age() << endl;
    cout << "-4-Name: " << people[3].get_name() << " Age: " << people[3].get_age() << endl;

    return 0;
}