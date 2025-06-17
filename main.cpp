#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

string addStrings (string line, string sumStr) 
{
    bool isCarry = false;
    if (line.size() > sumStr.size()) {
            swap(line, sumStr);
    }

    for (int i = sumStr.size() - 1 ; i >= 0; i--) {
        char digitA = line[i];
        char digitB = sumStr[i];

        // add two characters
        int sum = (digitA - '0') + (digitB - '0');
        if (isCarry) {
            sum += 1;
        }

        // check if it carries or not
        if (sum / 10 > 0) {
            isCarry = true;
        }
        else {
            isCarry = false;
        } 

        // update the sum
        sumStr[i] = sum % 10 + '0';
    }

    if (isCarry) {
        sumStr = '1' + sumStr;
    }

    return sumStr;
}

int main()
{
    string line;
    string sum;

    getline(cin, sum);

    while (getline(cin, line)) {
        if (line == "0") {
            break;
        }

        sum = addStrings(line, sum);
    }

    cout << sum <<endl;
    return 0;
}