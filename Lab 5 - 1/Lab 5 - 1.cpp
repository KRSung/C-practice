// Kyle Sung 016917041
// CECS 282 Lab 5 - Problem 1

#include <iostream>
#include <fstream>
using namespace std;

// reads data.txt file and inputs the integers to array
int * readData(int* arr) {
    int size = 0, i = 0;
    ifstream inputFile;
    inputFile.open("data.txt");
    // checks if the file was opened
    if (!inputFile) {
        cout << "Error: file could not be found. " << endl;
    }
    inputFile >> size;

    // reads lines from the file
    while (!inputFile.eof()) {
        inputFile >> arr[i];
        i++;
    }

    inputFile.close();
    return arr;
}

// Selection sort
void sorting(int* array, int size, int (*compare)()) {
    int minindex, temp = 0;
    for (int i = 0; i < size - 1; i++) {
        minindex = i;
        for (int j = i + 1; j < size; j++) {
            //            sorts the array in ascending order
            if (array[minindex] > array[j] && (*compare)() == 1) {
                minindex = j;
            }
            //            sorts the array in descending order
            if (array[minindex] < array[j] && (*compare)() == -1) {
                minindex = j;
            }
        }
        //        swap elements in the array
        temp = array[i];
        array[i] = array[minindex];
        array[minindex] = temp;
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
    int size = 0;
    ifstream inputFile;
    inputFile.open("data.txt");
    // checks if the file was opened
    if (!inputFile) {
        cout << "Error: file could not be found. " << endl;
    }
    // reads the first line of the file and assigns it to size;
    inputFile >> size;
    // closes file
    inputFile.close();
    // initializes array
    int* arr = new int[size];

    arr = readData(arr);

    // initializes function pointers
    int (*ascendingPtr)();
    ascendingPtr = ascending;
    int (*descendingPtr)();
    descendingPtr = descending;

    // unsorted array
    cout << "Unsorted: " << endl;
    writeToConsole(arr, size);

    // sorts in ascending order
    cout << "Sorted Ascending: " << endl;
    sorting(arr, size, ascendingPtr);
    // prints array
    writeToConsole(arr, size);

    // sorts in descending order
    cout << "Sorted Descending: " << endl;
    sorting(arr, size, descendingPtr);
    // prints array
    writeToConsole(arr, size);

    delete[]arr;

    return 0;
}
