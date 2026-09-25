#include <iostream>

using namespace std;

int main(){
    int i = 3;
    int j = 5;
    int sum = 0;
    while(i < 1000 || j < 1000){
        if (i < 1000){
        sum += i;
        i += 3;
        }
        if (j <  1000){
            if (j % 3 == 0) {
                j += 5; 
                continue;
            }
            sum += j;
            j += 5;
        }
    cout << "Sum: " << sum << endl;
        
    }
}