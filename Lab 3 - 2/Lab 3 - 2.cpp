#include <iostream>
#include <iomanip>
using namespace std;

void sort(double* score, int size) {
	double temp;
	for (int i = 0; i < size - 1; i++) {
		int smallestIndex = i;

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

double average(double* score, int numScores) {
	double total = 0;
	for (int i = 0; i < numScores; i++) {
		total += score[i];
	}
	double average = total / numScores;
	return average;
}

int main()
{
	int numTestScores;
	cout << "How many test scores will you enter? " << endl;
	cin >> numTestScores;
	double* testScores = new double[numTestScores];
	for (int i = 0; i < numTestScores; i++) {
		cout << "Enter test score " << i + 1 << ": " << endl;
		cin >> testScores[i];
	}

	sort(testScores, numTestScores);

	cout << "The test scores in ascending order, and their average, are:\n\nScores\n------\n" << endl;
	for (int i = 0; i < numTestScores; i++) {
		cout << fixed << setprecision(2) << testScores[i] << endl;
	}

	cout << "\nAverage Score: " << fixed << setprecision(2) << average(testScores, numTestScores) << endl;

	return 0;
}
