//  HW2Q2.cpp
//  HW2

#include "Account_definition.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Bank_account {
    private:
        Account account;
        double annual_interest_rate;
    public:
        Bank_account(): annual_interest_rate(0), account() {}
        Bank_account(string n,int i): annual_interest_rate(0), account(n,i) {}
        Bank_account(string n,int i,double b): annual_interest_rate(0), account(n,i,b) {}
        Bank_account(string n,int i,double b,double r): annual_interest_rate(r), account(n,i,b) {}
        void add_interest(unsigned int year) {
            double interest = (account.query())*(pow((1+annual_interest_rate),(year))-1);
            account.deposit(interest);
        }
        void display_balance() {
            cout << "$" << fixed << setprecision(2) << account.query() << endl;
        }
};

int main() {
    Bank_account A0("First", 1, 97);
    A0.display_balance();
    cout << endl;
    Bank_account A1("First", 1, 97, 0.055);
    A1.display_balance();
    A1.add_interest(8);
    cout << endl;
    A1.display_balance();
    cout<< "1/20/2023 " << "David Reynoso" << endl;
}
