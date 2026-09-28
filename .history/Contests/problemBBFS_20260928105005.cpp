#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


void solve(){

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr (n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    queue<int> list;
    vector<vector<int>> visited(n, vector<int>(m));
    list.push(pair({0, 0}));
    while(!list.empty()){
        
    }


}