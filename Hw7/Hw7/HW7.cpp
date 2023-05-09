//hw7

#include <iostream>
#include <chrono>
using namespace std;

long double xpower(long double x, int n){
    if (n==0) {
        return 1.0;
    }
    else {
        return x*xpower(x,n-1);
    }
}

long double xpower_h_helper(long double x, int n, long double result) {
    if (n==0) {
        return result;
    }
    else {
        return xpower_h_helper(x,n-1,x*result);
    }
}

long double xpower_h(long double x, int n) {
    return xpower_h_helper(x,n,1.0);
}

int main() {
    cout<<xpower(2,4)<<endl;
    cout<<xpower(3,3)<<endl;
    cout<<xpower_h(2,4)<<endl;
    cout<<xpower_h(3,3)<<endl;

    auto t0 = std::chrono::high_resolution_clock::now();
    xpower(1.01,2000);
    auto te = std::chrono::high_resolution_clock::now();
    std::cout << "Without the helper function " << std::chrono::duration_cast<std::chrono::nanoseconds>(te - t0).count() << " ns\n";
    t0 = std::chrono::high_resolution_clock::now();
    xpower_h(1.01,2000);
    te = std::chrono::high_resolution_clock::now();
    std::cout << "With the helper function " << std::chrono::duration_cast<std::chrono::nanoseconds>(te - t0).count() << " ns\n";
    cout<< "2/23/2023 " << "David Reynoso" << endl;

}
