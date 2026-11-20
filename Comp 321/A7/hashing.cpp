#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll hashFunc(string s){
    ll hash = 0;
    ll base = 31;
    for(int i = 0; i < s.length(); i++){
        hash += (s[i] - 'a' + 1) * pow(31, i);
    }
    return hash;
}

ll hashA(string s){
    const ll base = 31;
    const ll mod = 1e9 + 7;

    ll hashvalue = 0;
    ll curPow = 1;

    for(char c: s){
        ll currTerm = (c - 'a' + 1) * curPow % mod;
        hashvalue += currTerm % mod;

        curPow *= base;
    }
    return hashvalue;
}

ll hashB(string s){
    const ll base = 39;
    const ll mod = 1e9 + 9;

    ll hashvalue = 0;
    ll curPow = 1;

    for(char c: s){
        ll currTerm = (c - 'a' + 1) * curPow;
        hashvalue += currTerm;

        curPow *= base;
    }
    return hashvalue;
}


int main(){
    cout << hashA("abc") << "\n";
    cout << hashA("cba") << "\n";

}