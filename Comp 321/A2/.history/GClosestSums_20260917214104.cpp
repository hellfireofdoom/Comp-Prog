#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int counter = 1;
    while(cin >> n){
        vector<int>nums(n);
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }
        int m;
        cin >> m;
        vector<int> queries(m);
        vector<long long> closestSum(m, 2*1e7+1);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = nums[i] + nums[j];
                for(int k = 0; k < queries.size(); k++){
                    if (closestSum[k] == 2*1e7+1){
                        closestSum[k] = sum;
                    }
                    else{
                        if (abs(sum - queries[k]) < abs(queries[k] - closestSum[k]))
                            closestSum[k] = sum;
                    }
                }

            }
        }
        cout << "Case " << counter << ":\n";
        for(int i = 0; i < m; i++){
            cout << "Closest sum to " << queries[i] << " is " << closestSum[i] << ".";
            if (i != m - 1) cout << "\n"; 
        }
        counter++;



}
}