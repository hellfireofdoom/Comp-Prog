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
        return; // A 2-coin system with c_1 = 1 is always canonical
    
    vector<ll> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    
    ll biggest = coins[n - 1], sndBiggest = coins[n - 2];
    const ll T = biggest + sndBiggest;

    vector<int> dp(T, 0);
    vector<int> greedy(T, 0);
    int current_coin_idx = 0;

    for (ll v = 1; v < T; v++)
    {
        // 1. Calculate DP for optimal change
        dp[v] = v; // Worst case is using all 1-value coins
        for (int i = 0; i < n && coins[i] <= v; i++)
        {
            dp[v] = min(dp[v], 1 + dp[v - coins[i]]);
        }
        
        // 2. Calculate Greedy change dynamically in O(1)
        // Move to the next largest coin if it fits into our current value 'v'
        if (current_coin_idx + 1 < n && coins[current_coin_idx + 1] <= v) 
        {
            current_coin_idx++;
        }
        
        // Greedy takes 1 of the largest coin, plus the greedy result of the remainder
        greedy[v] = 1 + greedy[v - coins[current_coin_idx]];
        
        // 3. Compare and terminate early if a counterexample is found
        if (dp[v] < greedy[v])
        {
            flag = false;
            return;
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
    if (flag)
        cout << "canonical\n";
    else
    {
        cout << "non-canonical\n";
    }
}