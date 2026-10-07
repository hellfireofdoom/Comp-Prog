#include <iostream>
using namespace std;

int main(){
    int b, h, c;
    cin >> b >> h >> c;
    int num = 0;
    while(b > 2 || h != 0 || c != 0){
        b -= 2;
        h--;
        c--;
        num++;
        
    }
    cout << num <<"\n";
}