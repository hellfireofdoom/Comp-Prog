#include <iostream>
#include <deque>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = 0;
    deque<char> chars;
    while(n < s.length()){
        char c = s[n];
        if (c == '<'){
            if (!chars.empty()){
                chars.pop_front();
            }
        }
        else{
            chars.push_front(c);
        }
    }
    string res = "";
    while(!chars.empty()){
        res += chars.back();
        chars.pop_back();
    }
}