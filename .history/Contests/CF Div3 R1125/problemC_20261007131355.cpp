#include <map>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

void solve(){
    ll n;
    vector<ll> audienceLove;
    cin >> n;
    while(n--){
        ll love;
        cin >> love;
        audienceLove.push_back(love);
    }
    map<ll, pair<vector<int>, vector<int>>> freqs; // pair(even start indices, odd start)
    for(int i = 0; i < n-4; i++){
        int triadLove = audienceLove[i] + audienceLove[i+2] - audienceLove[i+4];
        cout << triadLove << "\n";
        if(i%2 == 0) freqs[triadLove].first.push_back(i);
        else{
            freqs[triadLove].second.push_back(i);

        } 
    }
    int total = 0;
    for(const auto& [_, indexPair]: freqs){
        int oddNum, evenNum;
        oddNum = indexPair.second.size();
        evenNum = indexPair.first.size();
        total += oddNum*evenNum;

        // find index of smallest num equal or greater than i+5
        vector<int> firstAr = indexPair.first;
        for(int i: firstAr){
            auto it = lower_bound(firstAr.begin(), firstAr.end(), i+5);
            if (it != firstAr.end()){
                ptrdiff_t index = distance(firstAr.begin(), it);
                int numGreater = evenNum - index;
                total += numGreater;
            }
            else{
                break;
            }

        }
        vector<int> secondAr = indexPair.second;
        for(int i: secondAr){
            auto it = lower_bound(secondAr.begin(), secondAr.end(), i+5);
            if (it != secondAr.end()){
                ptrdiff_t index = distance(secondAr.begin(), it);
                int numGreater = evenNum - index;
                total += numGreater;
            }
            else{
                break;
            }

        }
    }
    
    cout << total << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}