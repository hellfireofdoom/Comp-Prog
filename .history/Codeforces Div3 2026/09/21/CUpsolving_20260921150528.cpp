#include <iostream>
#include <cmath>
#include <vector>
#include <ranges>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m;
    string s;

    while (n--){
        int m;
        string s;
        cin >> m;
        cin >>  s;

        if (s[0] == 1){
            int count = 0;
            for(char c : s){
                if (c == '0'){
                    count++;
                }
            }
            cout << count << "\n";
        }
        else{

        vector<int> suf (m+1); // (0...m)
        // suf[i] = cost of suffix array starting from index i
        for (int i = m-1; i >= 0; i--){
            suf[i] = suf[i+1] + (s[i] == '0');
        }
        int ans = INT32_MAX, cost = 0;
        for (int i = 0; i < m; i++){
            ans = min(ans, cost + suf[i+1]);
            cost += s[i] == '1';
        }
        cout << ans << "\n";
    }



    }

}