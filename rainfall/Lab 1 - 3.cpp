// Kyle Sung 016917041 Lab 1 - 3

#include <iostream>
#include <fstream>
using namespace std;

void inputRainfall(int rainFall[], int size);
int calculateAverageRainFall(int rainFall[], int size);
void classifyAndDisplayRainfall(int rainFall[], int months);

int main() {
	const int size = 12;
	int rainFall[size];
	inputRainfall(rainFall, size);
	classifyAndDisplayRainfall(rainFall, size);
	return 0;
}	// end main

void inputRainfall(int rainFall[], int size) {
	int month = 0;
	ifstream inputFile;
	inputFile.open("C:\\Users\\KRSun\\OneDrive\\Desktop\\rainfall.txt");

	/*if (!inputFile) {
		cout << "File Could Not be Opened" << endl;
	}
	else {
		cout << "File Successfully Opened" << endl;
	}*/
	while (!inputFile.eof()) {
		inputFile >> rainFall[month];
		month++;
	}

	inputFile.close();
}

int calculateAverageRainFall(int rainFall[], int size) {
	double totalRainFall = 0;
	double averageRainFall;
	for (int i = 0; i < size; i++) {
		totalRainFall += rainFall[i];
	}
	averageRainFall = totalRainFall / (double)size;
	return round(averageRainFall);
}

void classifyAndDisplayRainfall(int rainFall[], int months) {
	int averageRainFall;
	int highestRainfall = rainFall[0];
	int highestMonth = 0;
	int lowestRainfall = rainFall[0];
	int lowestMonth = 0;
	string monthList[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	averageRainFall = calculateAverageRainFall(rainFall, months);
	cout << "The year's average monthly rainfall was " << averageRainFall << " mm" << endl;		

	for (int i = 0; i < months; i++) {
		if (rainFall[i] > highestRainfall) {
			highestRainfall = rainFall[i];
			highestMonth = i;
		}
		if (rainFall[i] < lowestRainfall) {
			lowestRainfall = rainFall[i];
			lowestMonth = i;
		}
	}

	cout << monthList[highestMonth] << " has the highest rainfall (" << highestRainfall << " mm)." << endl;
	cout << monthList[lowestMonth] << " has the lowest rainfall (" << lowestRainfall << " mm)\n" << endl;
	cout << "Month\tRainfall(mm)\tClassification" << endl;
	cout << "-----   ------------    --------------" << endl;

	for (int i = 0; i < months; i++) {
		if (rainFall[i] > (1.2 * (double)averageRainFall)) {
			cout << i + 1 << "\t" << rainFall[i] << "\t\tRainy" << endl;
			continue;
		}
		else if (rainFall[i] < (.75 * (double)averageRainFall)) {
			cout << i + 1 << "\t" << rainFall[i] << "\t\tDry" << endl;
			continue;
		}
		else {
			cout << i + 1 << "\t" << rainFall[i] << "\t\tAverage" << endl;
			continue;
		}
	}
}
