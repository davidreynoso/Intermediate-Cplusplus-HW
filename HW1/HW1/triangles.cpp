//  triangles.cpp
//  HW1
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    cout << "Please enter an integer: ";
    int nline;
    string tempstr;
    cin >> nline;
    ofstream fout("triangle.txt");
    for (int i = 0; i < nline; i++)
    {
        for (int j = i; j < nline; j++)
        {
            tempstr = tempstr + "*";
        }
        if (i == (nline - 1)){
            fout << setw(nline) << tempstr;
            tempstr = "";
        }
        else
        {
            fout << setw(nline) << tempstr << endl;
            tempstr = "";
        }
    }
    fout.close();
    cout<< "1/11/2023 " << "David Reynoso" << endl;
}
