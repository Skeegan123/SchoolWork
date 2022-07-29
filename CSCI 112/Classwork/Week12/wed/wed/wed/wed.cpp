#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

enum class Gender { man, woman, nonbinary };

class Person {
private:
    string name;
    int age;
    Gender gen;
public:
    Person() { name = "none"; age = 0; }
    Person(string n, int a) { name = n; age = a; }
    string get_name() { return name; }
    int get_age() { return age; }
    void set_name(string n) { name = n; }
    void set_age(int a) { age = a; }
    string get_gender();
    friend istream& operator>>(istream&, Person&);
};

bool compare(Person p1, Person p2) {
    return (p1.get_name() < p2.get_name());
}

istream& operator>>(istream& input, Person& p) {
    int gender;
    input >> p.name >> p.age >> gender;
    p.gen = (Gender)gender;
    return input;
}

string Person::get_gender() {
    vector<string> types{ "man", "woman", "nonbinary" };
    return types[(int)gen];
}

int main() {
    vector<Person> people;
    Person p;

    cin >> p;
    people.push_back(p);

    sort(people.begin(), people.end(), compare);

    cout << "Name: " << people[0].get_name() << " Age: " << people[0].get_age() << " Gender: " << people[0].get_gender() << endl;

    return 0;
}