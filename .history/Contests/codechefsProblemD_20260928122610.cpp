#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<long long>& arr, long long target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < target){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    if (arr[hi] == target){
        arr.erase(hi);
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> A(n * n);
    vector<long long> B(m * m);

    for (int i = 0; i < n * n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m * m; i++)
    {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool flag = true;
    for (auto &value: B){
    {
        long long cur = value;
        bool present = binarySearch(A, cur);
        if (!present)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
    cout << "FALSE\n";

    }
    else{ 
        cout << "TRUE\n";
}
}