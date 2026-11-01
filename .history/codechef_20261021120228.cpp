#include <iostream>
#include <string>
using namespace std;

int containsD(string n, int d){
    for(int i = 0; i < n.length(); i++){
        if (n[i] - '0' == d){
            return i;
        }
    }
    return 0;
}

void solve(){
    string n;
    int d;
    cin >> n >> d;
    // special cases: d = 0 and d = 9
    if (!containsD(n, d)){
        cout << "n: " << n << "\n";
        cout << n << "\n";
    }
    else{
        if (d == 9 && (n[0]) == '9'){
            cout << "1";
            for(int i = 0; i < n.length(); i++){
                cout << "0";
            }
        }
        else if (d == 0){
            int k = containsD(n, d);
            for(int i = 0; i < n.length(); i++){
                if (i >= k){
                    cout << 1;
                }
                else{
                    cout << n[i];
                }
            }

        }
        else if (d == 9){
            int k = containsD(n, d);
            for(int i = 0; i < n.length(); i++){
                if (i == k-1){
                    cout << n[i] - '0' + 1;
                }
                else if (i > k-1){
                    cout << 0;
                }
                else{
                    cout << n[i];
                }
            }
            
        }
        else{
            int k = containsD(n, d);
            for(int i = 0; i < n.length(); i++){
                if (i == k){
                    cout << n[i] - '0' + 1;
                }
                else if (i > k){
                    cout << 0;
                }
                else{
                    cout << n[i];
                }
            }
        }
        cout << "\n";

}
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}