#include <bits/stdc++.h>
using namespace std;

void dfsVisit(deque<int> &order, const unordered_map<int, vector<int>> &adjList, 
    vector<bool> &visited, int node){
    if (!visited[node]){
        visited[node] = true;
        for(int edge: adjList.at(node)){
            dfsVisit(order, adjList, visited, edge);
        }
        order.push_front(node);

    }
}

int main(){
    unordered_map<int, vector<int>> adjList;
    for(int i = 1; i <= 6; i++){
        adjList[i] = {};
    }
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[3].push_back(4);
    adjList[5].push_back(6);

    vector<bool> visited(7);
    deque<int> order;
    for(int i = 1; i <= 6; i++){
        if (!visited[i]){
            dfsVisit(order, adjList, visited, i);
        }
    }
    for(int i : order){
        cout << i << " ";
    }
    cout << "\n";
}