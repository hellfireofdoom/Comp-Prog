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
    int currMax = 0;
    int globalMax = 0;
    int price;
    for (int i = 0; i < n; i++){
        cin >> price;
        currMax = max({0, currMax += price - 20});
        globalMax = max(globalMax, currMax);
    }
    cout << globalMax << endl;
}