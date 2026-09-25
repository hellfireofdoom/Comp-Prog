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
    cin >> word;

    int n = word.length();

    vector<char> vowels(n); // stores the vowels surrounding GAS's
    int i = 0;
    int pos = 1;
    int currPos = 1;
    bool moreThanOne = false;
    while (pos < n)
    {   
        // + pos to compensate for the missing string
        pos = word.substr(pos).find("GAS") + pos; // find position of next GAS
        
        // No more GAS's and empty vowels vector
        if (pos == string::npos)
        {
            break;
        }
        // if there is still characters surrounding GAS
        if ((pos + 3) < word.length())
        {
            if (word[pos - 1] == 'A' || word[pos - 1] == 'E' || word[pos - 1] == 'I' ||
                word[pos - 1] == 'O' || word[pos - 1] == 'U')
            {
                // if not the same character
                if (word[pos - 1] == word[pos + 3])
                {
                // if yes, ---AGASA---                
                    // 3. if GAS are separated  --AGASA--EGASE---, return "+"
                    if (i > 0 && (pos - currPos) > 4 ) {
                        cout << "+";
                        moreThanOne = true;
                        break;
                    }
                    // Not separated --AGASAGASA--, continue to iterate
                    vowels[i] = word[pos - 1]; // store the vowel in vowels;
                    currPos = pos; // stores latest index
                    i++;
                }
                // advance to next possible GAS position
                pos += 4;
            }
                
            
        }
        // at the very end of word, just break;
        else
        {
            break;
            

        }
    }
    // 2. there was no GAS, return "-"
    if (i == 0){
        cout << "-\n";
        
    }
    // 1. At least one correct gas but not separated, print mod string
    else if (i > 0 && !moreThanOne){
        string modString = word.substr(0, currPos) + word.substr(currPos+4);
        cout << modString << endl;
    }
}
