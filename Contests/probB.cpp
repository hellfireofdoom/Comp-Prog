#include <bits/stdc++.h>
using namespace std;

// need to make string periodic
// using period, make the string rhythmic

// Cases:
// - Only one element k: string is rhythmic with period k
// - More than one element:
//      - There is one element which divides all other elements (e.g. 4 8 12): Nothing needs to be removed
//      - The case above doesn't apply: Need to remove all but one element?

// How to figure out which elements are in the same "group"?
// e.g. {4, 8, 12} and {3, 6, 12}
// Remove the elements in the smallest group
// Can store in set to remove duplicates

void solve()
{
    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    // for(int i : nums){
    //     cout << i << " ";
    // }
    // cout << "\n";
    map<int, bool> visited;
    for (int x : nums)
    {
        visited[x] = false;
    }

    map<int, vector<int>> groups;
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i])
            continue;
        int div = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] % div == 0)
            {
                cout << "div : " << div << " multiple: " << nums[j] << "\n";
                // initialize vector
                // if (groups[div] ){
                //     groups[div] = vector<int>{};
                // }
                groups[div].push_back(nums[j]);
                visited[j] = true;
            }
        }
    }
    if (groups.size() == 1)
        cout << 0 << "\n";
    else
    {
        // cout << "else branch\n";
        int minGroup = 1e9;
        // cout << "before checking max group size\n";
        for (auto &[div, multiple] : groups)
        {
            minGroup = min(minGroup, int(multiple.size()));
        }
        cout << minGroup << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}