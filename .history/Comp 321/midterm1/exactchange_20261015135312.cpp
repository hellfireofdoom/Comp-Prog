#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int amount;
    cin >> amount;
    int n;
    cin >> n;
    vector<int, vector<int>> dp(n, amount);

    vector<int> bills(n);
    while(n--){
        cin >> bills[n];
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}