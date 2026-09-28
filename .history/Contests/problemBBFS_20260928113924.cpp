#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


void solve(){

}

vector<pair<int, int>> getAdjacent(int x, int y, int n, int m){
    vector<pair<int,int>> res;
    int dX[4] = {0, -1, 0, 1};
    int dY[4] = {1, 0, -1, 0};

    for(int i = 0; i < 4; i++){
        int newX = x + dX[i];
        int newY = y + dY[i];
        if (newX < 0 || newX >= n || newY < 0 || newY >= m){
            continue;
        }
        else{
            res.push_back(pair(newX, newY));

        }
    }
    return res;
}

int minDistNeighbors(int x, int y, int n, int m, vector<vector<int>>& dist){
    int minDist = 1000;
    for(const auto& [a, b]: getAdjacent(x, y, n, m)){
        minDist = min(minDist, dist[a][b]);
        cout << x << " " << y << " " << minDist << "\n";
    }
    return minDist;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr (n, vector<int>(m));
    queue<pair<int, int>> list;
    vector<vector<int>> visited(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, 100));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                list.push(pair(i, i));
                visited[i][j] = true;
            }
        }
    }
    

    while(!list.empty()){
        // int x = list.front().first;
        // int y = list.front().second;
        const auto& [x, y] = list.front();
        list.pop();
        visited[x][y] = true;

        if (arr[x][y] == 0) dist[x][y] = 0;
        else{
            dist[x][y] = 1 + minDistNeighbors(x, y, n, m, dist);
        }
        for(const auto& [a, b] : getAdjacent(x, y, n, m)){
            if (!visited[a][b]){
                list.push(pair(a, b));
            }
        }



        
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }


}