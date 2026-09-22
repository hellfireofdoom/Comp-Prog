#include <iostream>
#include <vector>
using namespace std;


int solNums = 0;

int countRecur(vector<int>& prices, int total, int n, vector<vector<int>>& memo, vector<int>& sol){
    if (total == 0) {
        solNums++;
        return 1;
    }

    if (total < 0 || n == 0) return 0;

    if (memo[n-1][total] != -1)  return memo[n-1][total];
    int numSols = countRecur(prices, total - prices[n-1], n, memo, sol);
    if (solNums == 0){
    sol[n-1]++;
    if (numSols == 0) sol[n-1]--;
    }

    return memo[n-1][total] = countRecur(prices, total, n-1, memo, sol) + numSols;
}



int main(){
    int n;
    cin >> n;
    vector<int>prices(n, 0);
    for(int i = 0; i < n; i++){
        cin >> prices[i]; 
    }
    solNums = 0;

    int orders; 
    cin >> orders;
    while (orders--){
        int total;
        cin >> total;
        vector<int>sol(n); // keeps track of possible singular solution
        vector<vector<int>> memo(n, vector<int>(total, -1));

        int sols = countRecur(prices, total, n, memo, sol);
        if (sols == 0) cout << "Impossible\n";
        else if (sols == 1){
            for (int i = 0; i < n; i++){
                if (prices[i] != 0){
                    for (int j = 0; j < prices[i]; j++){
                        cout << i+1;
                        if (!i == n - 1 || !j == prices[i] - 1){
                            cout << " ";
                        }
                    }
                }
            }
        }
        else if(sols > 1) cout << "Ambiguous\n";
        



    }
}