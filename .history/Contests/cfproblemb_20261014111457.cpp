#include <iostream>
#include <string>
using namespace std;

void solve(){
    string s;
    cin >> s;
    bool flagLonger = false;
    bool flagShorter = false;
    for(int i = 1; i < s.length()-2; i++){
        char c = s[i];
        if (flagLonger && flagShorter){
            cout << 3 << "\n";
            return;
        }
        if (c == s[i-1] && c == s[i+1]){
            flagLonger = true;
        }
        else if (c != s[i-1] && c != s[i+1]){
            flagShorter = true;
        }
    }
    cout << 1 + flagLonger + flagShorter << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}