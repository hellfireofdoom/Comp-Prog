#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    int h;
    string s = "";
    // while(cin >> h >> s);
    // cin >> noskipws >>  s;
    // cin >> s;
    cin >> h;
    getline(cin, s);
    stringstream ss(s);

    int root = pow(2, h+1) - 1;
    if (!(ss >> s)){
        return root;
    }
    else{
        int i = 0;
        int dec;
        char prev = s[i];
        if (prev == 'L') dec = 1;
        else{
            dec = 2;
        }
        root -= dec;
        i++;
        while(i < s.length()){
            char cur = s[i];
            if (cur == prev){
                dec *= 2;
                
            }
            else if (cur == 'L'){
                dec = 2*dec - 1;
                prev = cur;
            }
            else if (cur == 'R'){
                dec = 2*dec + 1;
                prev = cur;
            }
                root -= dec;
            i++;
        }
        cout << root << "\n";

    }
}
