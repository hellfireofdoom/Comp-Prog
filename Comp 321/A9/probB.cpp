#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1500000000LL;
const long long MOD2 = 1000000000LL;

pair<long long, long long> fib (long long n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    long long diff = ((2 * p.second - p.first) % MOD2 + MOD2) % MOD2;
    long long c = (p.first * diff) % MOD2;
    long long d = ((p.first * p.first) % MOD2 + (p.second * p.second) % MOD2) % MOD2;
    if (n & 1)
        return {d, (c + d) % MOD2};
    else
        return {c, d};
}

void solve(){
    long long k, y;
    cin >> k >> y;
    y = y % MOD1;


    cout << k << " " << fib(y).first << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}