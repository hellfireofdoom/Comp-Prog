#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll S, C, K;
    cin >> S >> C >> K;
    if (C == 1) // if machine size is 1, then need one machine for every sock
    {
        cout << S << endl;
    }
    else
    {
        vector<ll> socks(S);
        for(int i = 0; i < S; i++){
            cin >> socks[i];
        }
        sort(socks.begin(), socks.end());

        ll machineNum = 0;
        ll machineMin = -1;
        ll machineCapacity = 0;

        for (int i = 0; i < S; i++)
        {
            if (machineMin == -1)
            {
                machineNum++;
                machineMin = socks[i];
                machineCapacity = 1;
            }
            else if (abs(socks[i] - socks[i - 1]) <= K && abs(socks[i] - machineMin) <= K)
            {
                machineCapacity++;
                if (machineCapacity == C)
                    machineMin = -1; // Next time, create new machine
            }
            // Create new machine
            else
            {
                machineNum++;
                machineMin = socks[i];
                machineCapacity = 1;
            }
        }
    }
}
