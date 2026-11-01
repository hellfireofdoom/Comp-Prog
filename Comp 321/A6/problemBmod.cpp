#include <bits/stdc++.h>
using namespace std;

// Points: 
// Order is preserved using insertOrder vector
// If the neighbor node is not trapped, then the current node is not trapped as well


void getInput(unordered_map<int, vector<int>> &forwardlist, 
            unordered_map<int, vector<int>> &backwardList, 
            vector<int> &insertOrder){
    int id;
    cin >> id;
    insertOrder.push_back(id);
    int n;
    cin >> n;
    forwardlist[id] = vector<int>();
    // backwardList[id] = vector<int>();
    
    int connect;
    while(n--){
        cin >> connect;
        forwardlist[id].push_back(connect);    
        backwardList[connect].push_back(id);

    }
}

void solve(unordered_map<int, vector<int>> &adjList, vector<bool>& modifyArray, int node){
    if (!modifyArray[node]){
        modifyArray[node] = true;        
        for(int neighbor: adjList[node]){
            solve(adjList, modifyArray, neighbor);
        }
    }
}

int main(){
    int t;
    cin >> t;
    unordered_map<int, vector<int>> forwardlist;
    unordered_map<int, vector<int>> backwardList;
    vector<int> insertOrder;
    while(t--){
        getInput(forwardlist, backwardList, insertOrder);
    }
    vector<bool> canEscape (1000, false);
    vector<bool> reachable(1000, false);  
    
    solve(forwardlist, reachable, 0);
    solve(backwardList, canEscape, 0);

    vector<int> resTrapped{};
    vector<int> resReachable{};
    for(int i = 0; i < insertOrder.size(); i++){
        int cur = insertOrder[i];
        if (!reachable[cur]){
            resReachable.push_back(cur);
        }
        if (!canEscape[cur]){
            resTrapped.push_back(cur);
    
        }
    }
    if (resTrapped.empty() && resReachable.empty()){
        cout << "NO PROBLEMS\n";
    }
    else{
    for(int i : resTrapped){
        cout << "TRAPPED " << i << "\n";
    }
    for(int i : resReachable){
        cout << "UNREACHABLE " << i << "\n";
    }
}

}