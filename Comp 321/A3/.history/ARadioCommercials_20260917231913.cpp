#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int maxProfit = 0;
    int price;
    for (int i = 0; i < n; i++){
        cin >> price;
        maxProfit = max(0, maxProfit += price);
    }
    cout << maxProfit << endl;
}