#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int length;
        char c;
        cin >> length >> c;
        string s;
        cin >> s;
        int lo = 0, hi = s.length()-1;
        int count = 0;
        while(lo < hi){
            if (s[lo] != s[hi]){
                if(s[lo] == c || s[hi] == c){
                    count++;
                }
                else{
                    count += 2;
                }
            }
        }
        cout << count << endl; 
    }
}