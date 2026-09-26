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
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
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
const T = 10;

void solve(){
    
        int n;
        cin >> n;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i]; 
        }
        for (int k = 0; k < T; k++)
        {

            for (int i = 0; i < n; i++)
            {

                int temp = nums[i];
                int cur = 0;

                while (temp > 0)
                {
                    int digit = temp % 10;
                    cur += digit * digit;
                    temp /= 10;
                }
                temp = cur;
                cur = 0;

                nums[i] = temp;
                // debug(nums[i]);
            }
            // debug(nums[i]);
        }
        ll sum = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                sum += nums[i] == nums[j];
            }
        }

        cout  << sum << "\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vector<vector<ll>> nums(3, vector<ll>(1001));

    int t;
    cin >> t;
    while (t--)
    {
        solve();

    }
}
