//  Kyle Sung 016917041
//  CECS 282  Lab 6 - 1

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

/*The function test checks whether the C string str is a palindrome.
If the C string str is a palindrome, then the function returns true;
otherwise, the function returns false.*/
bool testPalindrome(char* str) {
    int testStrLen = strlen(str);
    // checks if the string has an odd number of chars
    if (testStrLen % 2 == 1) {
        // finds the middle char
        int mid = testStrLen / 2;
        // checks if the characters i distance before and after middle are the same
        for (int i = 0; i <= mid; i++) {
            // returns false if the characters differ
            if (!(str[mid + i] == str[mid - i])) {
                return false;
            }
        }
    }
    else {
        // grabs two middle characters
        int mid1 = testStrLen / 2 - 1;
        int mid2 = testStrLen / 2;
        // checks if the characters i distance before and after middle are the same
        for (int i = 0; i <= mid1; i++) {
            // returns false if the characters differ
            if (!(str[mid1 - i] == str[mid2 + i])) {
                return false;
            }
        }
    }
    // return true if palindrome
    return true;
}

/* The function transform converts the given string raw into a standard form by converting
lowercase letters into the uppercase letters and removing all characters other than letters and numerals from the string.
The converted string will store in C string testStr. */
void transform(char* raw, char* testStr) {
    int testIndex = 0;
    for (char* i = raw; *i !=  '\0'; i++) {
        // checks if the character is alpha numeric
        if (isalnum(*i)) {
            // appends an upper case version of the string to the test string then updates index
            *(testStr + testIndex) = toupper(*i);
            testIndex++;
        }
    }
    // appends the null terminatorto the end of testStr
    *(testStr + testIndex) = '\0';
}

int main()
{
    while (true) {
        cout << "Enter a String or \"-1\" to quit: " << endl;
        string userString;
        // grabs the user entered line and sets it as userString's value
        getline(cin, userString);

        if (userString == "-1") {
            break;
        }

        // turns userString into a raw c style string
        char* raw = &(userString[0]);
        // creates a pointer testStr the same length of the raw string
        char* testStr = new char[strlen(raw)];

        // takes the raw input and turn it into a testable c style string
        transform(raw, testStr);


        // tests if the converted string is a palendrome
        if (testPalindrome(testStr)) {
            cout << "\'" << userString << "\' is a palindrome.\n" << endl;
        }
        else {
            cout << "\'" << userString << "\' is not a palendrome.\n" << endl;
        }
    }
    return 0;
}
