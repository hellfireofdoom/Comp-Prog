#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ";_print(x); cerr << endl;
#else#define debug(x);
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T, class V> void _print(vector <T, V> p);
template <class T, class V> void _print(set <T, V> p);
template <class T, class V> void _print(map <T, V> p);
template <class T, class V> void _print(multiset <T, V> p);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T, class V> void _print(vector <T, V> p) {cerr << "[ "; for (T i : v){_print(i); cerr < " "; } cerr << "]";}
template <class T, class V> void _print(set <T, V> p) {cerr << "[ "; for (T i : v){_print(i); cerr < " "; } cerr << "]";}
template <class T, class V> void _print(map <T, V> p) {cerr << "[ "; for (T i : v){_print(i); cerr < " "; } cerr << "]";}

void solve(){

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
