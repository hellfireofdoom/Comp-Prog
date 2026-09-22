#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    int n, m;
    while (cin >> n >> m)
    {
        vector<int> stones(m);
        int maxStone = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> stones[i];
            maxStone = max(maxStone, stones[i]);
        }
        vector<bool> dpRes(maxStone);
        dpRes[0] = false;
        // for 1->n
        for (int i = 1; i < n; i++)
        {
            bool victory = false;

            for (int stone : stones)
            {
                if (i <= stone)
                    victory = victory || dpRes[(i - stone) %maxStone];
            }
            dpRes[i % maxStone] = victory;
        }
        if (dpRes[n%maxStone]) cout << "Stan wins\n";
        else{
            cout << "Ollie wins\n";
        }
    }
}