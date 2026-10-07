#include <iostream>
#include <queue>
#include <string>
using namespace std;

void solve(int n)
{
    int dishLoc = 1;
    int total = 0;

    while (n--)
    {
        string order;
        int m;
        cin >> order >> m;
        if (order == "DROP")
        {
            total += m;

            cout << "DROP " << dishLoc << " " << m << "\n"; // DROP dishLoc m
        }
        else if (order == "TAKE")
        {
            if (total != 0) // previous order was drop
            {
                int newLoc = dishLoc % 2 + 1;
                cout << "MOVE " << dishLoc << "->" << newLoc << " " << total << "\n"; // MOVE dishloc->newLoc m
                dishLoc = newLoc;
                total = 0;
            }
            cout << "TAKE " << dishLoc << " " << m << "\n";
        }
        // cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        solve(n);
        cin >> n;
        if (n != 0)
        {
            cout << "\n";
        }
    }
}