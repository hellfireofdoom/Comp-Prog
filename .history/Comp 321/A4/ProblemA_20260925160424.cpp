#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(){
    ll n;
    cin >> n;
    vector<ll> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    ll discount = 0;
    int a, b, c;
    for(int i = 0; i < n - 2; i = i+ 3){
        discount += prices[i];
    }
    cout << discount << "\n";
}