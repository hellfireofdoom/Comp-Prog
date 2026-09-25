#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main(){
    int W = 10;
    int N = 4;
    vector<int> values{4,4,8, 1};
    vector<int> weights{3, 5, 6, 2};
    int SUM = accumulate(values.begin(), values.end());
    vector<int> dpOneD(W+1);
    for(int i = 1; i <= N; i++){
        for(int j = SUM; j >= values[i-1]; j--){
            dpOneD[j] = min(dpOneD[j], dpOneD[j - weights[i-1]] + )
        }
    }

    // vector<vector<int>> twoDp(2, vector<int>(W+1, 0));
    // for(int i = 1; i <= N; i++){
    //     for(int w = 1; w<= W; w++){
    //         if (weights[i-1] > w) twoDp[i%2][w] = twoDp[(i+1)%2][w];
    //         else{
    //         for(int k = 1; k * weights[i-1] <= w; k++){
    //             twoDp[i%2][w] = max(twoDp[(i+1)%2][w], twoDp[(i+1)%2][w - k * weights[i-1]] + k*values[i-1]);
    //         } 
    //     }
    //     }
    // }
    // vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    // for(int i = 1; i <= N; i++){
    //     for(int w = 1; w <= W; w++){
    //         if (weights[i] > W) dp[i][w] = dp[i-1][w];
    //         else{
    //             dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
    //         }
    //     }
    // }
    cout << "Max value: " << twoDp[N%2][W] << endl;

    

}