#include <iostream>
#include <stack>
using namespace std;

void solve(){
    int n;
    cin >> n;
    stack<int> coords;
    while(n--){
        int num;
        cin >> num;
        coords.push(num);
    }
        int cur = 0;
        while(!coords.empty()){
            int coord = coords.top();
            coords.pop();
            cur = (coord - cur) * 2 + cur;
        }
        cout << cur/2 << "\n";
    }


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}