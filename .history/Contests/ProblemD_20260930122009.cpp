#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> stairs(n);
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }

    unordered_map<int, int> frequency;
    int maxNum = 0;
    for(int i = 0; i < n; i++){
        int staircaseKey = stairs[i] - i;
        maxNum = max(maxNum, ++frequency[staircaseKey] - 1);
    }
    cout << n-1-maxNum << "\n";

    // int l = 0, r = 0;
    // int maxLength = 0;
    // while(r != n-1){
    //     if(stairs[r+1] == stairs[r] + 1){
    //         r++;
    //         maxLength = max(maxLength, r-l);
    //     }
    //     else{
    //         l = r+1;
    //         r = r+1;
    //     }
    // }
    // cout << n-1 - maxLength << "\n";
    

}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}