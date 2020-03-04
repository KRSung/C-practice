// Kyle Sung 016917041 Lab 1 - 1

#include <iostream>
#include <string>
using namespace std;

int main() {
	string userString;
	string a;
	int addedNum;
	int userAnswer = 0;
	cout << "Enter an integer, the sum of all odd digits will be returned: " << endl;

	cin >> userString;
	
	for (int i = 0; i < userString.size(); i++) {
		a = userString.at(i);
		addedNum = stoi(a);
		if (addedNum % 2 != 0) {
			userAnswer += addedNum;
		}
	}

	cout << userAnswer << endl;

	return 0;
}