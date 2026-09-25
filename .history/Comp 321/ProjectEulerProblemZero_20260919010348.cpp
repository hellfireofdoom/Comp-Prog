#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    for (int i = 1; i < 815000; i = i+2){
        sum += i*i;
    }
    cout << "Sum = " << sum << endl;
}