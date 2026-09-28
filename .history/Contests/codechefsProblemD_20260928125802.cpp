#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<long long> &arr, long long target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (arr[hi] == target)
    {
        arr.erase(arr.begin() + hi);
        return true;
    }
    else
    {
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
    long long asize = n*n;
    long long Bsize = m*m;
    int i = 0, j = 0;
    while(i < asize && j < Bsize){
        if (B[j] > A[i]) i++;
        else if (B[j] == A[i]) {
            i++;
            j++;
        }
        else{
            break;
        }
    }
    if (j == Bsize) cout << "TRUE\n";
    else{
        cout << "FALSE\n";
    }
    if (!flag)
        {
            cout << "FALSE\n";
        }
        else
        {
            cout << "TRUE\n";
        }
}