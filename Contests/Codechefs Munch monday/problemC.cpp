#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;

    long long freq[26] = {0};
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    long long len = sizeof(freq) / sizeof(freq[0]);
    sort(freq, freq + len, greater<long long>());
    int curLarg = 0;
    for (int i = 0; i < k; i++)
    {
        freq[curLarg]--;
        if (curLarg < 25 && freq[curLarg] < freq[curLarg + 1])
        {
            curLarg++;
        }
        else if (curLarg > 0 && freq[curLarg] < freq[curLarg - 1])
        {
            curLarg--;
        }
    }
    long long weight = 0;
    for(int i = 0; i < 26; i++){
        weight += freq[i] * freq[i];
    }
    cout << weight << "\n";
}