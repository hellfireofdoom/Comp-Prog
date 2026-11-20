#include <bits/stdc++.h>
using namespace std;

vector<int> LPSRes(string &s){
    if (s.empty()) return vector<int>{0};
    vector<int> lps (s.length());
    lps[0] = 0;
    int len = 0;
    int i = 1;
    // int maxLPS = 0;
    while(i < s.length()){
        // cout << "i: " << i << "\n";
        if (s[i] == s[len]){
            len++;
            lps[i] = len;
            // maxLPS = max(maxLPS, lps[i]);
            i++;
        }
        else{
            if (len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
        return lps;
    }


void solve(){
    string s;
    // cin >> s;
    getline(cin, s);
    int n = s.length();
    cout << n - LPSRes(s).back() << "\n";
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }

}