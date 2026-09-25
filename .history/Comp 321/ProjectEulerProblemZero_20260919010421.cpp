#include <iostream>
using namespace std;

int main(){
    long long sum = 0;
    for (long long i = 1; i < 815000; i = i+2){
        sum += i*i;
    }
    cout << "Sum = " << sum << endl;
}