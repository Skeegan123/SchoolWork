#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream ifs;
    string ip;
    vector<string> ipList;

    ifs.open("addresses.txt");

    if (ifs.is_open()) {
        while (getline(ifs, ip)) {
            ipList.push_back(ip);
        }
    } else {
        cout << "Error opening file";
    }

    ifs.close();

    sort(ipList.begin(), ipList.end());

    for (unsigned int i = 0; i < ipList.size(); i++) {
        cout << ipList[i] << endl;
    }
}