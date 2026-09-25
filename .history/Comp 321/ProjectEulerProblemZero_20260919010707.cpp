#include <iostream>
#include <cmath>
using namespace std;


int main(){
    long long sum = 0;
    for (long long i = 1; i < 815000; i = i+2){
        sum += i*i;
    }
    cout << "Sum = " << sum << endl;

    int n = 815000;
    int n = ceil(n/2.0);
    cout << "Sum = " << (n * (2*n - 1) * (2*n + 1))/3 << endl;
}