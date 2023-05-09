//  Account_definition.h
//  HW2

#ifndef Account_definition_h
#define Account_definition_h

#include <iostream>
#include <string>
using namespace std;

class Account {
    private:
        double balance;
        string name;
        int ID;
    public:
        Account(): name(""), ID(0), balance(0) {}
        Account(string n, int i): name(n), ID(i), balance(0) {}
        Account(string n, int i,double b): name(n), ID(i), balance(b) {}
        string show_name() {return name;}
        int show_ID() {return ID;}
        double query() {return balance;}
        void deposit(double a) {
            if (a >= 0){
                balance += a;
            }
        }
    void withdraw(double c) {
        if (c > balance) {
            cout << "5 dollar penalty charged for attempting to withdraw more than available" << endl;
            if (balance < 5) {
                balance = 0;
            }
            else {
                balance -= 5;
            }
        }
        else if (c >= 0){
            balance -= c;
        }
    }
    
};

#endif /* Account_definition_h */
