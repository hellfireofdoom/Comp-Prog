#include <iostream>
#include <queue>
#include <string>
using namespace std;

void solve(int n)
{
    int dishLoc = 1;
    int total = 0;
    bool prevWasDrop = false;
    while (n--)
    {
        string order;
        int m;
        cin >> order >> m;
        if (order == "DROP")
        {
            total += m;
            prevWasDrop = true;
            cout << "DROP " << dishLoc << " " << m << "\n"; // DROP dishLoc m
        }
        else if (order == "TAKE")
        {
            if (prevWasDrop) // previous order was drop
            {
                int newLoc = dishLoc % 2 + 1;
                cout << "MOVE " << dishLoc << "->" << newLoc << " " << total << "\n"; // MOVE dishloc->newLoc m
                dishLoc = newLoc;
                prevWasDrop = false;

            }
            cout << "TAKE " << dishLoc << " " << m << "\n";
            total -= m;
        }
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