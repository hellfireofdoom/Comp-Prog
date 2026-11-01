#include <iostream>
using namespace std;

void solve(){
    int cheese, sausage;
    cin >> cheese >> sausage;
    if (cheese <= sausage){
        cout << -1 << "\n";
    }
    else{
        cout << sausage << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}