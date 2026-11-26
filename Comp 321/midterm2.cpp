#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    while(b){
        int r = a % b; a = b; b = r;
    }
    return a;
}

double pow (double a, int n){
    
}

vector<bool> retSieve(){
    int n = 1000000;
    vector<bool> sieve(n+1, true);
    for(int i = 2; i <= n; i++){
        if (sieve[i]){
            for(int j = i; j <= n; j += i){
                sieve[j] = false;
            }
        }
    }

    return sieve;

}

bool primeChecker(long long n){
    vector<bool> sieve = retSieve();
    for(int i = 2; i * i < n; i++){
        if (sieve[i]){
            if (n % i == 0) return false;
        }
    }
    return true;
}

int main(){

}