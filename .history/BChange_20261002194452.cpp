#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ones = 0;
    int tens = 0;
    int hunds = 0;
    while(n--){
        long long amount;
        cin >> amount;
        // (ceil(amount/1000) * 1000 - amount)
        long long remainder = 1000 - amount%1000; 
        hunds += remainder / 100;
        remainder %= 100;
        tens += remainder/ 10;
        remainder %= 10;
        ones += remainder
}
    cout << ones << " " << tens << " " << hunds << "\n";
}