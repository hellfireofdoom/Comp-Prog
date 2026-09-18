#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, P;
    cin >> n >> P;
    int maxProfit = 0;
    int price;
    for (int i = 0; i < n; i++){
        cin >> price;
        maxProfit = max(vector<int>{0, maxProfit, maxProfit + price - 20});
    }
    cout << maxProfit << endl;
}