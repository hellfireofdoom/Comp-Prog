#include <iostream>
#include <cmath>
#include <vector>

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

        vector<int> suf (m+1);
        // suf[i] = cost of suffix array starting from index i
        for (int i = m-1; i >= 0; i--){
            suf[i] = suf[i+1] + (s[i] == '0');
        }
        int ans = INT32_MAX, cost = 0;
        for (int i = 0; i <= m; i++){
            ans = min(ans, cost + suf[i]);
            cost += s[i] == '0';
        }

        cout << ans << "\n";



    }

}