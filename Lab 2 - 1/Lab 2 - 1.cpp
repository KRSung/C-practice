// Kyle Sung 016917041
// CECS 282 Lab 2 - 1

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
    double get_balance() const {
        return this->balance;
    }
    void deposit(double money) {
        if (money > 0) {
            this->balance += money;
        }
    }
};

int main()
{
    Account my_account(100);     // Set up my account with $100
    my_account.deposit(50);
    my_account.withdraw(175);   // Penalty of $20 will apply
    my_account.withdraw(25);

    cout << "Account balance: " << my_account.get_balance() << "\n";

    my_account.withdraw(my_account.get_balance());  // withdraw all
    cout << "Account balance: " << my_account.get_balance() << "\n";

    return 0;
}

