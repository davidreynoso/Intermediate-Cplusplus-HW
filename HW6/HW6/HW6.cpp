//Hw6

#include <iostream>
#include "pair.h"
#include <string>
using namespace std;

int main() {
    Pair<int> pair1(3, 4);
    Pair<int> result1 = pair1.sum_diff();
    cout << result1.get_first() << " " << result1.get_second() << endl;
    cout << "Expected: 7 -1" << endl;
    Pair<double> pair2(3.5, 4.1);
    Pair<double> result2 = pair2.sum_diff();
    cout << result2.get_first() << " " << result2.get_second() << endl;
    Pair<string> pair3("x", "y");
    Pair<string> result3 = pair3.sum_diff();
    cout << result3.get_first() << " " << result3.get_second() << endl;
    cout<< "2/17/2023 " << "David Reynoso" << endl;
}
