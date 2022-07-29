#include <iostream>
#include <string>
using namespace std;

class Mon {
    private: 
        string name;
        int age;
    public:
        string get_name() { return name; }
        int get_age() { return age; }
        void set_name(string nameIn) { name = nameIn; }
        void set_age(int ageIn) { age = ageIn; }
        Mon();
        Mon(string, int);
        void printMon();
};

Mon::Mon() {
    cout << "Default Constructor called" << endl;
    name="none";
    age=-1;
}

Mon::Mon(string nm, int ageIn) {
    name = nm;
    age = ageIn;
}

void Mon::printMon() {
    cout << "Name: " << get_name() << endl;
    cout << "Age: " << get_age() << endl;
}

int main()
{
    Mon obj1;
    obj1.set_name("Alexis");
    obj1.set_age(20);
    Mon obj2("Keegan", 19);

    obj1.printMon();
    obj2.printMon();

    return 0;
}
