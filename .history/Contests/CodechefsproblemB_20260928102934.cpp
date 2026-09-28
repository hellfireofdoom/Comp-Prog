#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int counter = 1;
int DFS(const vector<vector<int>> &arr, vector<vector<int>> &dist, int x, int y)
{
    cout << "DFS " << counter << "\n";

    if (x < 0 || x >= dist.size() || y < 0 || y >= dist[0].size())
        return 1000;
    else if (dist[x][y] != -1)
        return dist[x][y];
    else
    {
        cout << "else branch\n";
        int a = DFS(arr, dist, x - 1, y);
        int b = DFS(arr, dist, x + 1, y);
        int c = DFS(arr, dist, x, y - 1);
        int d = DFS(arr, dist, x, y + 1);

        if (arr[x][y] == 0)
        {
            dist[x][y] = 0;
            return 0; 
        }
        

        dist[x][y] = 1 + min({a, b, c, d});
        counter++;
        return dist[x][y];
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

    DFS(arr, dist, 0, 0);

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
