//  Kyle Sung 016917041
//  Lab 6 - 1

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

bool testPalindrome(char* str) {
    int testStrLen = strlen(str);
    if (testStrLen % 2 == 1) {
        int mid = testStrLen / 2;
        for (int i = 0; i <= mid; i++) {
            if (!(str[mid + i] == str[mid - i])) {
                return false;
            }
        }
    }
    else {
        int mid1 = testStrLen / 2 - 1;
        int mid2 = testStrLen / 2;
        for (int i = 0; i <= mid1; i++) {
            if (!(str[mid1 - i] == str[mid2 + i])) {
                return false;
            }
        }
    }

    return true;
}
/*The function test checks whether the C string str is a palindrome. 
If the C string str is a palindrome, then the function returns true; 
otherwise, the function returns false.*/

void transform(char* raw, char* testStr) {
    int testIndex = 0;
    for (char* i = raw; *i !=  '\0'; i++) {
        if (isalnum(*i)) {
            *(testStr + testIndex) = toupper(*i);
            testIndex++;
        }
    }
    *(testStr + testIndex) = '\0';
}
/* The function transform converts the given string raw into a standard form by converting 
lowercase letters into the uppercase letters and removing all characters other than letters and numerals from the string. 
The converted string will store in C string testStr. */

int main()
{
    while (true) {
        cout << "Enter a String or \"-1\" to quit: " << endl;
        string userString;
        getline(cin, userString);

        if (userString == "-1") {
            break;
        }

        char* raw = &(userString[0]);
        char* testStr = new char[strlen(raw)];


        transform(raw, testStr);


        if (testPalindrome(testStr)) {
            cout << userString << " is a palindrome." << endl;
        }
        else {
            cout << "is not a palendrome." << endl;
        }
    }
    return 0;
}
