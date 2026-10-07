#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> stairs(n);
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }

    int l = 0, r = 0;
    int maxLength = 0;
    while(r != n-1){
        if(stairs[r+1] > stairs[r]){
            r++;
            maxLength = max(maxLength, r-l);
        }
        else{
            l = r+1;
            r = r+1;
        }
    }
    if (maxLength == n-1){
        cout << "0\n";
    }
    else if (maxLength == 0){
        cout << n-1 << "\n";
    }
    else{
        cout << n - maxLength << "\n";
    }
    cout << "maxlength: " << maxLength << "\n";

}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}