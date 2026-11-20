#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Original approach, compare the first string of length i with all other substrings
// of length i
// this doesn't work for input strings like
// abcdeab or abcdea
// since the shortest pattern that explains the above string is abcde
// KMP? 

ll hashFunc(string s){
    const ll base = 31;
    const ll mod = 1e9 + 7;

    ll hashRes = 0;
    ll power = 1;

    for(char c: s){
        ll currTerm = ((c - 'a' + 1) * power) % mod;
        hashRes += currTerm % mod;
        power *= base;
    }

    return hashRes;
}

// Compares the hashes of the og string and every substring of size i
// Returns false if different hash or if same hash and one of the characters are different
bool iteration(string og, string s, int i, int n){
        // cout << "og: " << og << "\n";
    
        for(int j = i; j < n;){
            string copied = "";
            int k = j+i;
            while(j < k){
                copied += s[j];
                j++;
            }
            // cout << "copied: " << copied << "\n";
            if (hashFunc(og) != hashFunc(copied)){
                return false;
            }
            else{
                
                    for(int l = 0; l < og.length(); l++){
                        if (og[l] != copied[l]) return false;
                    }
                
            }
        }
        return true;

}

void solve(){
    string s;
    cin.ignore();
    getline(cin, s);
    int n = s.length();
    for(int i = 1; i <= n; i++){
        if (n % i != 0) continue;
        string og = "";
        for(int j = 0; j < i; j++){
            og += s[j]; 
        }

        if (iteration(og, s, i, n)){
            cout << i << "\n";
            return;
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