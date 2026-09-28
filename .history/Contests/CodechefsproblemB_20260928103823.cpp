#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int counter = 1;
int DFS(const vector<vector<int>> &arr, vector<vector<int>> &dist, vector<vector<bool>> &visited, int x, int y)
{
    // cout << "DFS " << counter << "\n";

    if (x < 0 || x >= dist.size() || y < 0 || y >= dist[0].size())
        return 1000;
    else if (visited[x][y])
        return dist[x][y];
    else
    {
        cout << "x: " << x << " y : " << y << "\n";
        
        visited[x][y] = true;
        int a = DFS(arr, dist, visited, x - 1, y);
        int b = DFS(arr, dist, visited, x + 1, y);
        int c = DFS(arr, dist, visited, x, y - 1);
        int d = DFS(arr, dist, visited, x, y + 1);

        if (arr[x][y] == 0)
        {
            dist[x][y] = 0;
            cout << "was zero\n";
            return 0;
        }
        else
        {
            dist[x][y] = 1 + min({a, b, c, d});
            counter++;
            return dist[x][y];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    cout << "getting input\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "after input\n";
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    DFS(arr, dist, visited, 0, 0);

    cout << "second print\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j];
        }
        cout << '\n';
    }
}
