#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int amount;
    cin >> amount;
    int n;
    cin >> n;
    vector<int, vector<int>> dp(n, amount);

    vector<int> coins(n);
    while(n--){
        cin >> coins[n];
    }

    for(int i = 0)

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}