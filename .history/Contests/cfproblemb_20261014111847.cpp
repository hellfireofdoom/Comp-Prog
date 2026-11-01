#include <iostream>
#include <string>
using namespace std;

void solve(){
    string s;
    cin >> s;
    bool flagLonger = false;
    bool flagShorter = false;
    for(int i = 1; i < s.length()-1; i++){
        char c = s[i];
        
        if (c == s[i-1] && c == s[i+1]){
            flagLonger = true;
        }
        else if (c != s[i-1] && c != s[i+1]){
            flagShorter = true;
        }
        if (flagLonger && flagShorter){
            cout << 3 << "\n";
            return;
        }
    }
    cout << 1 + flagLonger + flagShorter << "\n";
    if (flagLonger || flagShorter) cout << 2 << "\n";
    else{
        cout << 1 << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}