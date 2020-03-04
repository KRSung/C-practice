// Kyle Sung 016917041
// CECS 282 Lab 5 - Problem 2

#include <iostream>
#include <string>
using namespace std;

//Class of Persons

class Person{
private:
    string name;
    float salary;

public:
    void setPerson();
    string getName();
    float getSalary();
};

// Swaps by reference
void order(Person** ob1, Person** ob2) {
    Person *temp = *ob1;
    *ob1 = *ob2;
    *ob2 = temp;
}

//Creates person with user input name and salary
void Person::setPerson(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter Salary: ";
    cin >> salary;
}
//Returns person's name
string Person::getName(){
    return name;
}
//Returns person's name
float Person::getSalary(){
    return salary;
}
//n is an the number of person objects stored in the array
//if s is true, then sort by name;otherwise, sort by salary.
void bsort(Person** p, int n, bool s){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if ((s == false && p[i]->getSalary() > p[j]->getSalary()) || (s == true && p[i]->getName() > p[j]->getName())){
                order(&p[i], &p[j]);
            }
        }
    }
}
//This method print the array of name and salary
void print(Person** p, int n){
    for (int i = 0; i < n; i++)
    {
        cout << (p[i]->getName()) << " " << (p[i]->getSalary()) << endl;
    }
}

//This method is user inputted and prints out unsorted
//and sorted list via alphabetical and salary base
int main(){
    int n;
    cout << "Enter number of person: ";
    cin >> n;
    Person ** p = new Person*[n];
    for (int i = 0; i < n; i++){
        p[i] = new Person();
        p[i]->setPerson();
    }
    cout << "\nUnsorted order" << endl;
    print(p, n);
    cout << endl;
    cout << "Sorted base of name alphabetically" << endl;
    bsort(p, n, true);
    print(p, n);
    cout << endl;
    cout << "Sorted based on salary from least to greatest" << endl;
    bsort(p, n, false);
    print(p, n);
    cout << endl;

    delete []p;
    return 0;
}
