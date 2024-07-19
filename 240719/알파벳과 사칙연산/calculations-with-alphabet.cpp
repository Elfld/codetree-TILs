#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int calculate(string input) {
    int tmp = input[0] - '0';
    for (int i = 1; i <= input.size()/2; i++) {
        switch (input[2 * i - 1]) {
        case '+':
            tmp += input[2 * i] - '0';
            break;
        case '-':
            tmp -= input[2 * i] - '0';
            break;
        case '*':
            tmp *= input[2 * i] - '0';
            break;
        }
    }
    return tmp;
}

int main() {
    
    string inputLine;
    getline(cin, inputLine);

    vector<vector<int>> alphLocation(6);
    vector<vector<int>> simbLocation(3);

    for (int i = 0; i < inputLine.size(); i++) {
        if (inputLine[i] >= 'a' && inputLine[i] <= 'f') {
            alphLocation[inputLine[i] - 'a'].push_back(i);
        }
        else {
            simbLocation[(inputLine[i] - '+') / 2].push_back(i);
        }
    }


    int maximum = INT_MIN;

    for (int i = 0; i < 4096; i++) {
        int alph[6]{ 1 };
        for (int p = 0; p < 6; p++) {
            alph[p] = ((i >> (5 - p) * 2) & 0b11)+1 ;
        }
        for (int j = 0; j < alphLocation.size(); j++) {
            for (int k = 0; k < alphLocation.at(j).size(); k++) {
                inputLine[alphLocation.at(j).at(k)] = alph[j] + '0';
            }
        }
        maximum = max(calculate(inputLine), maximum);
    }

    cout << maximum;

}