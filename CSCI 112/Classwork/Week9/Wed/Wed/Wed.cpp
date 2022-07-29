
#include <iostream>
using namespace std;

int main()
{
    string first, last;
    int age;

    cout << "Enter first name, last name, and age: ";
    cin >> first >> last >> age;

    cout << "Hello, " << first << " " << last << "\n" << age << " years old is a wonderful age" << endl;

    return 0;
}