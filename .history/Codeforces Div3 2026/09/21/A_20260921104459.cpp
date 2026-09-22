#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m;
    for (int i = 0; i < n; i++){
        cin >> m;
        int minWeak = 10;
        int k;
        for(int j = 0; j < m; j++){
            cin >> k;
            minWeak = min(minWeak, k);
        }
        cout << minWeak << "\n";
    }
}