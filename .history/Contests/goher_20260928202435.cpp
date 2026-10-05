#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> chars;
        for(char c: s){
            chars.push_back(c);
        }
        sort(chars.begin(), chars.end());

        string res = "";
        for(int c: chars){
            res += c + 'a';
        }
        cout << res << "\n";

    }
}