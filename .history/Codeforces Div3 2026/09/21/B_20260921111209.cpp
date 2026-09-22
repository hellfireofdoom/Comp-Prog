#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    long long a, b, c;

    long long res = 0;
    while (cin >>a>>b>>c){
        if (a < b){
            if (c > 2*(b-a)) a = a + c;
        }
        else if (a >= b){
            a = a + c;
        }

        cout << b - a << "\n";

    }


}