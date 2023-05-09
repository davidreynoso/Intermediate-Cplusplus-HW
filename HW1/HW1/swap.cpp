//  swap.cpp
//  HW1

#include <iostream>
#include <string>
using namespace std;

//goober and gooby are just to hold one value so we can update a variable and still
//use its value to update the next variable
void swap1(int &a, int &b){
    int goober = a;
    a = b;
    b = goober;
}

void swap2(int *a, int *b){
    int gooby = *a;
    *a = *b;
    *b = gooby;
}

int main() {
    int a=3, b=1;
    swap1(a,b);
    cout<<"a="<<a<<" b="<<b<<endl;
    swap2(&a,&b);
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<< "1/11/2023 " << "David Reynoso" << endl;
}
