#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int cheese, sausage;
    cin >> cheese >> sausage;
    if (cheese <= sausage){
        cout << -1 << "\n";
    }
    else{
        cout << min(sausage, cheese-sausage) << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}