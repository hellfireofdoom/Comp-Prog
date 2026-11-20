#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// for length of substring i, check if all substrings of length i are anagrams
//

bool iteration(ll i, const string& s)
{
    ll freq[26] = {0};
    for (ll j = 0; j < i; j++)
    {
        freq[s[j] - 'a']++;
    }
    
    for (ll j = i; j < s.length(); j = j+i)
    {
        ll freqCopy[26];
        copy(begin(freq), end(freq), begin(freqCopy));
        
        string curr = s.substr(j, i);
        for(char c: curr){
            if (freqCopy[c - 'a'] == 0){
                return false;
            }
            else{
                freqCopy[c - 'a']--;
            }
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (s.length() == 1)
        cout << -1 << "\n";
    else
    {
        for (ll i = 1; i < s.length(); i++)
        {
            if (s.length() % i != 0){
                continue;
            }
            // cout << "i: " << i << "\n";
            if (iteration(i, s)){
                cout << s.substr(0, i) << "\n";
                return 0;
            }
        }
        cout << "-1\n";
    }
}