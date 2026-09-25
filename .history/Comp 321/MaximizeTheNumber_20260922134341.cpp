#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string num = to_string(n);
        int cur = 0;
        cout << "Before: " << num << endl;


    while(k != 0 && cur < num.length()){
        int maxInd = cur;
        
        for(int i = cur+1; i <= k; i++){
            if (i == num.length()) break;
            if (num[maxInd] - '0' < num[i] - '0'){
                maxInd = i; //123 -> 312
            }
        }
        int max = num[maxInd] - '0';
        cout << "Max: " << max << endl;
        // swapping 
        for(int i = maxInd; i > cur; i--){
            num[i] = num[i-1];
            cout << "Swap" << i << ": " << num[i] << endl;
        }
        num[cur] = max;

        k -= maxInd - cur;
        cur++;
    }

    cout << "After: " << num << endl;
}