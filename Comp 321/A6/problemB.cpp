#include <bits/stdc++.h>
using namespace std;

// Points: 
// Order is preserved using insertOrder vector
// If the neighbor node is not trapped, then the current node is not trapped as well


void getInput(unordered_map<int, vector<int>> &adjList, vector<int> &insertOrder){
    int id;
    cin >> id;
    insertOrder.push_back(id);
    int n;
    cin >> n;
    adjList[id] = vector<int>();
    int connect;
    while(n--){
        cin >> connect;
        adjList[id].push_back(connect);
    }
}

void solve(unordered_map<int, vector<int>> &adjList, vector<bool>& reachable, vector<bool>& canEscape, int node, vector<int> &listBeforeZero ){
    if (node == 0 and !listBeforeZero.empty()){
        for(int el: listBeforeZero){
            canEscape[el] = true;
            for(int i : adjList[el]){
                canEscape[i] = true;
            }
        }
        listBeforeZero = {};

    }
    else if (!reachable[node]){
        reachable[node] = true;
        listBeforeZero.push_back(node);
        for(int neighbor: adjList[node]){
            if (canEscape[neighbor]){
                canEscape[node] = true;
            }
            solve(adjList, reachable, canEscape, neighbor, listBeforeZero);
        }
        if (!listBeforeZero.empty()){
        listBeforeZero.pop_back();
        }

    }


}

int main(){
    int t;
    cin >> t;
    unordered_map<int, vector<int>> adjList;
    vector<int> insertOrder;
    while(t--){
        getInput(adjList, insertOrder);
    }
    vector<bool> canEscape (1000, false);
    vector<bool> reachable(1000, false);  
    canEscape[0] = true;
    
    vector<int> listBeforeZero{};
    solve(adjList, reachable, canEscape, 0, listBeforeZero);

    vector<int> resTrapped{};
    vector<int> resReachable{};
    for(int i = 0; i < insertOrder.size(); i++){
        int cur = insertOrder[i];
        if (!reachable[cur]){
            resReachable.push_back(cur);
        }
        else if (!canEscape[cur]){
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