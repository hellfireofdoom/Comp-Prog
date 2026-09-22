#include <iostream>
#include <cmath>

using namespace std;






int main(){
    int n;
    cin >> n;
    int m;
    string word;
    while (cin >> m >> word){
        string pre;
        string suf;
        int cost = 1e9;

        for(int i = 0; i <= m+1; i++){
            
            pre = word.substr(0, i);
            suf = word.substr(i, word.length());

            int one = 0;
            int zero = 0;
            for (char c : pre){
                if (c == '1') one++;
            }
            for(char c : suf) {
                if (c == '0') zero++;
            }
            cost = min(cost, zero+one);

        }
        cout << cost << "\n";

    }
    

}