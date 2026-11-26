#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<bool> sieve(N+1, true);
    int k = 0;
    for(int i = 2; i <= N; i++){
        if (sieve[i]){
            k++;
            if (k == K){
                cout << i << "\n";
                return 0;
            }
            for(int j = 2*i; j <= N; j += i){
                if (sieve[j]){
                    k++;
                    if (k == K){
                        cout << j << "\n";
                        return 0;
                    }
                    sieve[j] = false;
                }
            }
        }
    }
}