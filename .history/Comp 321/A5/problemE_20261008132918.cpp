#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
// #include <string>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    map<string, ll> toReadList;
    queue<pair<int, pair<string, int>>> toBeAdded;
    while(n--){
        string title;
        int pages;
        cin >> title >> pages;
        if (title < "Jane Eyre"){
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
    ll totalTime = 0;
    

}