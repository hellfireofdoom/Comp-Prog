#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    map<string, ll> toReadList;
    queue<pair<int, pair<string, int>>> toBeAdded;
    while(n--){
        string line;
        readline
        string title;
        int pages;
        cin >> title >> pages;
            cout << title << "\n";

        if (title < "\"Jane Eyre\""){
            toReadList.insert({title, pages});
        }
    }
    while(m--){
        int toBeAddedTime;
        string title;
        int pages;
        cin >> toBeAddedTime >> title >> pages;
        toBeAdded.push(pair(toBeAddedTime, pair(title, pages)));
    }
    ll timeElapsed = 0;
    while(!toReadList.empty()){
        timeElapsed += toReadList.begin()->second; // Add time
        toReadList.erase(toReadList.begin()->first); // Remove first book to read
        if(!toBeAdded.empty() && toBeAdded.front().first <= timeElapsed){
            const auto& [title, pages] = toBeAdded.front().second;
            toBeAdded.pop();
            if(title < "\"Jane Eyre\""){
                toReadList.insert({title, pages});
            }
        }

    }
    timeElapsed += k;
    cout << timeElapsed << "\n";

}