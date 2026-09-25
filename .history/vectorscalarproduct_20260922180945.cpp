#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        vector<int> inc(n);
        vector<int> dec(n);
        for(int i = 0; i < n; i++){
            cin >> inc[0];
        }
        for(int i = 0; i < n; i++){
            cin >> dec[0];
        }

        sort(inc.begin(), inc.end());
        sort(dec.rbegin(), dec.rend());

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += inc[i] * dec[i];
        }
        cout << "Case #" << i << ": " << sum << endl;

    }
}