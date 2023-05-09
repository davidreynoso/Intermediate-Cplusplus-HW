

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int gcd(int a, int b) {
    int x = abs(a);
    int y = abs(b);
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    if (x == y) {
        return x;
    }
    if (x > y) {
        return gcd(x-y, y);
    }
    return gcd(x, y-x);
}

int lcm(int x, int y) {
    return ((x*y)/gcd(x,y));
}

class Frac {
private:
    int numerator = 0;
    int denominator = 1;
    bool Not_a_number = false;
public:
    Frac() {simplify();}
    Frac(int a): numerator(a) {simplify();}
    Frac(int a, int b) {
        if (b < 0) {
            numerator = -a;
            denominator = abs(b);
        }
        else if (b == 0) {
            Not_a_number = true;
        }
        else {
            numerator = a;
            denominator = b;
        }
        simplify();
    }
    void simplify() {
        int a = gcd(numerator,denominator);
        numerator = numerator/a;
        denominator = denominator/a;
    }
    friend ostream& operator << (ostream& out,  const Frac & fraction){
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }
/*    friend ostream& operator << (ostream& out, const Frac && fraction){
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }*/
    Frac operator+ (Frac& x) {
        Frac a;
        int m = lcm(denominator,x.denominator);
        a.numerator = (m*numerator/denominator) + (m*x.numerator/x.denominator);
        a.denominator = m;
        a.simplify();
        return a;
    }
    Frac operator - (const Frac& x) {
        Frac a;
        int m = lcm(denominator,x.denominator);
        a.numerator = (m*numerator/denominator) - (m*x.numerator/x.denominator);
        a.denominator = m;
        a.simplify();
        return a;
    }
    Frac operator * (const Frac& x) {
        Frac a;
        a.numerator = numerator * x.numerator;
        a.denominator = denominator * x.denominator;
        a.simplify();
        return a;
    }
    Frac operator / (const Frac& x) {
        Frac a;
        a.numerator = numerator * x.denominator;
        a.denominator = x.numerator * denominator;
        a.simplify();
        return a;
    }
    bool operator == (const Frac& x) const {
        if ((numerator == x.numerator) and (denominator == x.denominator)) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator < (const Frac& x) {
        int m = lcm(denominator,x.denominator);
        if ((m*numerator/denominator) < (m*x.numerator/x.denominator)) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator > (const Frac& x) {
        int m = lcm(denominator,x.denominator);
        if ((m*numerator/denominator) > (m*x.numerator/x.denominator)) {
            return true;
        }
        else {
            return false;
        }
    }
};



int main() {
    ofstream fout("pout.txt");
    
    Frac A(4,-5);
    A();
    Frac B(7,11);
    fout << A;
    cout<<A<<endl;
    cout<<A+B<<endl;
    cout<<A-B<<endl;
    cout<<A*B<<endl;
    cout<<A/B<<endl;
    cout<<(A==B)<<endl;
    cout<<(A<B)<<endl;
    cout<<(A>B)<<endl;
    A=Frac(-12,15);
    cout<<(A==B)<<endl;
    cout<< "1/27/2023 " << "David Reynoso" << endl;
}
