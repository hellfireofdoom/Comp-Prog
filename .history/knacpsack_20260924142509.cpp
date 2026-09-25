#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int W = 10;
    int N = 4;
    vector<int> values{3,4,8, 1};
    vector<int> weights{3, 5, 6, 2};
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    for(int i = 1; i <= N; i++){
        for(int w = 1; w <= W; w++){
            if (weights[i] > W) dp[i][w] = dp[i-1][w];
            else{
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            }
        }
    }
    cout << "Max value: " << dp[N+1][W+1] << endl;

    

}