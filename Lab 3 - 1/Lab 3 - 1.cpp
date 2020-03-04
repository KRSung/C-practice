// Kyle Sung 016917041
// CECS 282  Lab 3 - 1

#include <iostream>
#include <iomanip>
using namespace std;

void sort(double score[], int size) {
	int smallestIndex;
	double temp;
	for (int i = 0; i < size - 1; i++) {
		smallestIndex = i;
		
		for (int j = i + 1; j < size; j++) {
			if (score[smallestIndex] > score[j]) {
				smallestIndex = j;
			}
		}

		temp = score[smallestIndex];
		score[smallestIndex] = score[i];
		score[i] = temp;
	}
}

double average(double score[], int numScores) {
	double total = 0;
	for (int i = 0; i < numScores; i++) {
		total += score[i];
	}
	double average = total / numScores;
	return average;
}

int main() {
	int numTestScores;
	cout << "How many test scores will you enter? " << endl;
	cin >> numTestScores;
	double * testScores = new double[numTestScores];
	for (int i = 0; i < numTestScores; i++) {
		cout << "Enter test score " << i + 1 << ": " << endl;
		cin >> testScores[i];
	}

	sort(testScores, numTestScores);
	
	cout << "The test scores in ascending order, and their average, are:\n\nScores\n------\n" << endl;
	for (int i = 0; i < numTestScores; i++) {
		cout << testScores[i] << endl;
	}

	cout << "\nAverage Score: " << fixed << setprecision(2) << average(testScores, numTestScores) << endl;

	delete []testScores;

	return 0;
}