#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> pairs;
    while(n--){
        int x, y;
        cin >> x >> y;
        pairs.push_back(pair(x, y));
    }

    sort(pairs.begin(), pairs.end());

    int numRooms = 1;
    int currLowHighBound = pairs[0].second;

    for(int i = 1; i < n; i++){
        auto const [x, y] = pairs[i];
        if (x > currLowHighBound){
            numRooms++;
            currLowHighBound = y;
        }
        else{
            currLowHighBound = min(currLowHighBound, y);
        }
    }
    cout << numRooms << "\n";
}