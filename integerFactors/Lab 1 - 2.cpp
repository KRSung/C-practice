//Kyle Sung 016917041 Lab 1 - 2

#include <vector>
#include <iostream>
using namespace std;

int main(){
    int userInt;
    cout << "Enter an integer and the program will return its factors: " << endl;
    cin >> userInt;
    cout << "The factors are: " << endl;

    vector<int> factors;
    
    for (int i = 1; i <= userInt; i++) {
        if (userInt % i == 0) {
            factors.push_back(i);
        }
    }

    for (int i = 0; i < factors.size(); i++) {
        if (factors[i] != 0) {
            cout << factors[i] << endl;
        }
        else {
            break;
        }
    }
    return 0;
}
