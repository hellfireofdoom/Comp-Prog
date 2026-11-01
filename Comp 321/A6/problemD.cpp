#include <bits/stdc++.h>
using namespace std;

// If some vertices are only connected by one edge, need to include it
// Idea: use k blue edges to build a spanning tree, then use red edges to build the remaining tree
// if it is not yet a spanning tree. if not possible, replace one blue edge by another blue edge and do the same
// when building blue edge tree, start with vertices which are not connected to many red edges (low red-degree)

// Use modified kruskal's?
// if blue edge, set weight to 0
// if red, set to 1
// keep adding edges weight 0 until we reach k

// Asked gemini, need to find a way to "trick" an MST algorithm to build an MST using the MAXIMUM number of blue edges
// and the MINIMUM number of blue edges. mathematical property, if k is between the min and the max then it is possible to create a spanning tree
// using k blue edges

// first thing that comes to mind is to change the weight of the edges
// to find minimum, set blue edges weight to 1 and red to 0. the alg will try to pick as many red and as little blue as possible
// to find maximum, set blue edges weight to 0 and red to 1. the alg will try to pick as many blue

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        else
        {
            return parent[i] = find(parent[i]);
        }
    }
    void unite(int a, int b){
        int s1 = find(a), s2 = find(b);
        if (s1 != s2){
        if (rank[s1] < rank[s2]){
            parent[s1] = s2; 
        }
        else if (rank[s1] > rank[s2]){
            parent[s2] = s1;
        }
        else{
            parent[s2] = s1;
            rank[s1]++;
        }
    }

}
};

// returns true if edge a is lighter than b
bool comparator(const vector<int> &a,  const vector<int> &b){
    return a[0] < b[0];
}
void printEdge(vector<int> edge){
    cout << "cost: " << edge[0] << " from: " << edge[1] << " to: " << edge[2] << "\n";
}

int kruskal(int n, vector<vector<int>> edges){
    DSU dsu(n);

    int cost = 0, count = 0;
    for(auto edge: edges){
        int c = edge[0], f = edge[1], t = edge[2];
        // printEdge(edge);
        if (dsu.find(f) != dsu.find(t)){
            dsu.unite(f, t);
            cost += c;
            count++;
            if (count == n-1){
                break;
            }

        }
    }
    return cost;
}

void getInput(vector<vector<int>> &edges)
{
    char c;
    int f, t;
    cin >> c >> f >> t;
    if (c == 'B')
    {
        edges.push_back({1, f, t});
    }
    else
    {
        edges.push_back({0, f, t});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges;
    // cout << "before getting input\n";

    while (m--)
    {
        getInput(edges);
    }
    // cout << "got input\n";

    int minBlue, maxBlue;

    //blue edges at the back, will prioritize taking red edges
    // cout << "before minBlue\n";
    sort(edges.begin(), edges.end(), comparator);
    minBlue = kruskal(n, edges);
    // cout << "got minBlue\n";

    // blue edges at the front, will prioritize taking blue edges
    sort(edges.rbegin(), edges.rend(), comparator);
    maxBlue = kruskal(n, edges);
    // cout << "got maxBlue\n";

    if (minBlue <= k && k <= maxBlue) cout << 1 << "\n";
    else{
        cout << 0 << "\n";
    }

}