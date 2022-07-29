#include <iostream>
using namespace std;
#include <vector>

int main(void) {
    vector<int> ints;

    int temp;
    int sum = 0;

    cout << "Enter numbers to sum together (0 to end)\n";

    while (cin >> temp && temp != 0) {
        ints.push_back(temp);
    }

    for (unsigned int i = 0; i < ints.size(); ++i) {
        sum += ints[i];
    }

    cout << "The sum of the numbers entered, divided by 2 is " << sum / 2 << '\n';

    return 0;

}