#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sumIndex(int i, vector<int> fenwick){
    int total = 0;
    while(i > 0){
        total += fenwick[i];
        i -= i & -i;
    }
    return total;
}

void solve(vector<int>& arr, vector<int>& fenwick){
    string operation;
    cin >> operation;
    if (operation == "F"){
        int i;
        cin >> i;
        int currBit = arr[i];
        arr[i] ^= 1; // flip bit
        int diff = currBit?-1:1;
        while(i < arr.size()){
            fenwick[i] + diff;
            i += i & -i;
        }

    }
    else if (operation == "C"){
        int a, b;
        cin >> a >> b;
        cout << sumIndex(b, fenwick) - sumIndex(a-1, fenwick);

    }
}

int main(){
    int N, K;
    vector<int> arr(N+1);
    vector<int> fenwick(N+1);
    while(K--){
        solve(arr, fenwick);
    }
}