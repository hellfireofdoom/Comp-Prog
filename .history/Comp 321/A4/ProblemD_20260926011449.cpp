#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;





int main()
{
    int n;
    cin >> n;
    if (n == 2)
        cout << "canonical\n";
    else
    {
        vector<long long> coins(n);
        for (int i = 0; i < n; i++)
            cin >> coins[i];

        sort(coins.begin(), coins.end());
        ll x = coins[n - 1];
        ll y = coins[n - 2];
        ll biggest = x+y; 

        vector<vector<long long>> dp(n + 1, vector<long long>(x+y));
        for(ll i = 0; i < x+y; i++){
            dp[0][i] = INFINITY;
        }
        for(ll i = 1; i < n; i++){
            dp[i][0] = 0;
        }
        
        for(ll i = 1; i <= n; i ++){
            for(ll j = 1; j <= biggest; j++){
                for(long long k = 1; k*coins[i] <= j; k++){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j - k*coins[i]] + k);
                }
            }
        }
        bool flag = true;
        for(ll i = x; i < biggest; i++){
            int greedySol = dp[i][n];
            for(ll j = n-1; j >= 1; j--){
                if (dp[i][j] < greedySol){
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag){
            cout << "canonical\n";
        }
        else{
            cout << "non-canonical\n";
        }

    }
}