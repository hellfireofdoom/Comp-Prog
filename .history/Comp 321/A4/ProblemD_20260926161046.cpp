#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

bool flag = true;
void solve()
{
    int n;
    cin >> n;
    if (n == 2)
        return;
    else
    {
        vector<ll> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        ll biggest = coins[n-1], sndBiggest = coins[n - 2];
        const ll T = biggest + sndBiggest;
        vector<vector<ll>> dp(n + 1, vector<ll>(T, T+1));

        for (ll i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll v = 1; v < T; v++)
            {
                if (coins[i - 1] > v)
                {
                    dp[i][v] = dp[i - 1][v];
                }
                // If we can repeat coins
                for (ll k = 1; k * coins[i - 1] <= v; k++)
                {
                    dp[i][v] = k + dp[i][v - k * coins[i - 1]];
                }
            }
        }
        for(ll v = T; v >= 2; v--){
            for(ll i = n-1; i > 2; i--){
                // if there exists an optimal non-greedy solution 
                if (dp[i][v] > dp[i-1][v]) {
                    flag = false; 
                    return;
                }
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    if (flag) cout << "canonical\n";
    else{
        cout << "non-canonical\n";
    }
}