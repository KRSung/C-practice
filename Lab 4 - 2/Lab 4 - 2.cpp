// Kyle Sung 016917041
// CECS 282 Lab 4 - Problem 2

#include <iostream>
#include <fstream>
using namespace std;

// reads data.txt file and inputs the integers to array
int readData(int** arr) {
    int size = 0, i = 0;
    ifstream inputFile;
    inputFile.open("data.txt");
    // checks if the file was opened
    if (!inputFile) {
        cout << "Error: file could not be found. " << endl;
    }
    inputFile >> size;

    *arr = new int[size];

    // reads lines from the file
    while (!inputFile.eof()) {
        // inputs lines form the file to the array
        inputFile >> *((*arr)+i);
        i++;
    }

    inputFile.close();
    return size;
}

// Selection sort
void sorting(int* array, int size, int (*compare)()) {
    int minIndex, temp;
    temp = 0;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
//            sorts the array in ascending order
            if (array[minIndex] > array[j] && (*compare)() == 1) {
                minIndex = j;
            }
//            sorts the array in descending order
            if (array[minIndex] < array[j] && (*compare)() == -1) {
                minIndex = j;
            }
        }
        //        swap elements in the array
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}


int ascending() {
    return 1;
}

int descending() {
    return -1;
}


// Prints to console
void writeToConsole(int* arr, int last) {
    for (int i = 0; i < last; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;
}

int main() {

    // initializes array
    int size;
    int* arr;
    size = readData(&arr);
    // pointer functions
    int (*ascendingPtr)();
    ascendingPtr = ascending;
    int (*descendingPtr)();
    descendingPtr = descending;

    // Print before sorting
    cout << "Before Sorting" << endl;
    writeToConsole(arr, size);

    // sorts in ascnding order
    cout << "Sorted Ascending" << endl;
    sorting(arr, size, ascendingPtr);
    // prints array
    writeToConsole(arr, size);

    // sorts in descending order
    cout << "Sorting Descending" << endl;
    sorting(arr, size, descendingPtr);
    // prints array
    writeToConsole(arr, size);

    
    delete []arr;

    return 0;
}
