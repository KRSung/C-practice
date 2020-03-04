// Kyle Sung 016917041
// CECS 282 Lab 2 - 2

#include <iostream>
using namespace std;

class Account {
private:
    double balance;
public:
    Account() {
        this->balance = 0;
    }

    Account(double money) {
        this->balance = money;
    }

    void withdraw(double money) {
        if (money <= this->balance) {
            this->balance -= money;
        }
        else {
            cout << "Error: you have attempted to withdraw more money than that which is available in your account\nA penalty of $20 will apply" << endl;
            this->balance -= 20;
        }

    }

    void addInterest(double& investment, double interestRate) {
        investment = investment * (1 + interestRate / 100);
    }

    double get_balance() const {
        return this->balance;
    }

    void deposit(double money) {
        if (money > 0) {
            this->balance += money;
        }
    }

    int timeUntilDoubleInvestment(double investment, double interestRate) {
        double doubleInvestment = 2 * investment;
        int month = 0;
        while (investment < doubleInvestment) {
            addInterest(investment, interestRate);
            month++;
        }
        return month;
    }
};


int main() {
    double investment = 0;
    double interestRate = 0;
    int userMenu = 0;

    Account my_account;

    while (true) {
        cout << "Enter 1 to enter the initial investment. Type 2 to enter the annual interest rate, or type \"-1\" to quit:" << endl;
        cin >> userMenu;
        if (userMenu == -1) {
            cout << "Goode Bye" << endl;
            break;
        }
        else if (userMenu == 1) {
            cout << "Enter the initial investment:  " << endl;
            cin >> investment;
        }
        else if (userMenu == 2) {
            cout << "Enter the annual interest rate:  " << endl;
            cin >> interestRate;
        }

        if (investment > 0 && interestRate > 0) {
            cout << "The investment of "<< investment << " with an interest rate of " << interestRate <<
                " will double in " << my_account.timeUntilDoubleInvestment(investment, interestRate/12) << " month(s)\n" << endl;
        }
    }
    return 0;
}