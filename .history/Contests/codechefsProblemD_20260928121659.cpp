#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long binarySearch(vector<long long> arr, long long target)
{
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
    for (auto &it = A.begin(); it == A.end(); it++)
    {
        long long cur = *it;
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