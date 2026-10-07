#include <iostream>
#include <vector>
using namespace std;


// O(n)
vector<int> buildFenwickTree(vector<int> arr){
    int n = arr.size() + 1;
    vector<int> fenwick(n);
    copy(arr.begin(), arr.end(), fenwick.begin() + 1);
    for(int i = 1; i < n; i++){
        int j = i + (i & -i);
        fenwick[j] += fenwick[i]; 
    }
    return fenwick;
}

// O(log n)
int sumIndex (const vector <int>& arr, int n){
    int total = 0;
    int i = n;
    while(i > 0){
    total += arr[i];
    i -= i & -i;
}
return total;
}

// O(log n)
int rangeSum(const vector<int>& arr, int a, int b){
    return sumIndex(arr, b) - sumIndex(arr, a-1);
}


int main(){

    vector<int> fenwick = buildFenwickTree(vector<int>{1,2,3,4,5});
    for(int i = 1; i < fenwick.size(); i++){
    cout << sumIndex(fenwick, i);
    cout << "\n";
    }}