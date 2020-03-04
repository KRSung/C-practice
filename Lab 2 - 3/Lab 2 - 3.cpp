// Kyle Sung 016917041
// CECS 282  LAB 2 - 3

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

class Bank {
private:
    Account S;
    Account C;

public:
    void deposit(double amount, string account) {
        if (account == "S") {
            S.deposit(amount);
        }
        else if (account == "C") {
            C.deposit(amount);
        }
    }
    void withdraw(double amount, string account) {
        if (account == "S") {
            S.withdraw(amount);
        }
        else if (account == "C") {
            C.withdraw(amount);
        }
    }
    void transfer(double amount, string account) {
        if (account == "S") {
            S.withdraw(amount);
            
            if (amount < S.get_balance()) {
                C.deposit(amount);
            }
        }
        else if (account == "C") {
            if (amount < C.get_balance()) {
                S.deposit(amount);
            }
            C.withdraw(amount);
        }
    }

    void print_balances() {
        cout << "Checking: " << C.get_balance() << endl;
        cout << "Savings: " << S.get_balance() << endl;

    }
};

int main()
{
    Bank my_bank;
    cout << "Inital bank balances: \n";
    my_bank.print_balances(); /* set up empty accounts */

    cout << "Adding some money to accounts: \n";
    my_bank.deposit(1000, "S"); /* deposit $1000 to savings */
    my_bank.deposit(2000, "C"); /* deposit $2000 to checking */
    my_bank.print_balances();

    cout << "Taking out $1500 from checking, and moving $200 from";
    cout << " savings to checking.\n";
    my_bank.withdraw(1500, "C"); /* withdraw $1500 from checking */
    my_bank.transfer(200, "S"); /* transfer $200 from savings */
    my_bank.print_balances();

    cout << "Trying to transfer $900 from Checking.\n";
    my_bank.transfer(900, "C");
    my_bank.print_balances();

    cout << "Trying to transfer $900 from Savings.\n";
    my_bank.transfer(900, "S");
    my_bank.print_balances();

    return 0;
}