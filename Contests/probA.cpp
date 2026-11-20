#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    if (l == 0 && r == 0) cout << 0 << "\n";
    else if (l * r > 0){
        cout << r - l << "\n";
    }
    else {
        if (l + r == 0 || l + r == 1){
            cout << 0 << "\n";
        }
        else{
            cout << abs(r + l) - 1 << "\n";
        }   
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}