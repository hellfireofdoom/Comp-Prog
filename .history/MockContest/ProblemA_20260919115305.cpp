#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <functional>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    int n = word.length();
    cin >> word;

    vector<char> vowels(n); // stores the vowels surrounding GAS's
    int i = 0;
    int pos = 1;
    while (pos < n)
    {
        
        pos = word.substr(pos).find("GAS"); // find position of next GAS
        // No more GAS
        if (pos == string::npos)
        {

            cout << "-\n";
            break;
        }
        // if there is still characters surrounding GAS
        if (pos > 0 && (pos + 3) < word.length())
        {
            if (word[pos - 1] == 'A' || word[pos - 1] == 'E' || word[pos - 1] == 'I' ||
                word[pos - 1] == 'O' || word[pos - 1] == 'U')
            {
                // if not the same character
                if (word[pos - 1] != word[pos + 3])
                {
                    pos += 4;
                }
                // if yes, ---AGASA---
                else
                {
                    vowels[i] = word[pos - 1];
                    i++;
                }
            }
        }
        // either at very start or very end of word
        else
        {
            if ((pos + 3) < word.length())
            {
                pos += 4;
            }
            else
            {
                break;
            }
            {
            }

            vowels[i] = word[pos - 1];
            i++;
        }
    }

    else
    {
        char firstVowel = word[pos - 1]; // vowel before first GAS, for
        int sndpos = word.substr(pos + 1).find("GAS");
    }
}
}
