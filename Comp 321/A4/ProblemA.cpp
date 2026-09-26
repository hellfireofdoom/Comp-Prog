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
    sort(prices.rbegin(), prices.rend());
    ll discount = 0;
    for(int i = 2; i < n; i = i+ 3){
        discount += prices[i];
    }
    cout << discount << "\n";
}