#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rec(vector<int>& remaining){
    if (remaining.empty()) return vector<int>{};
    int max = remaining[0];
    int num = 1;
    while (num < remaining.size() || remaining[num] == max){
        num++;
    }

    vector<int> res{};
    int curr;
    for(int i = num; i < remaining.size(); i++){
        if (remaining[i] == remaining[i-1]) curr++;
        else{
            curr = 1;
        }
        if (curr > num){
            int now = remaining[i];
            while(remaining[i] == now){
                res.push_back(now);
                remaining.erase(remaining.begin()+i);
            }
        }
    }
    vector<int> resNew = rec(res);
    remaining.insert(remaining.end(), resNew.begin(), resNew.end());
    return remaining;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++) cin >> vec[i];

        sort(vec.rbegin(), vec.rend());
        rec(vec);
        for(int i = 0 ; i < vec.size(); i++){
            cout << vec[i];
            if (i != vec.size()-1) cout << " ";
        }
        cout << "\n";

    }
}