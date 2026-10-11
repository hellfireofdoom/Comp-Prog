#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string s1 = "Jane Eyre";
    string s2 = "Jane Eyr";

    getline(cin, s);
    stringstream ss(s);
    string t;
    while(getline(ss, t, '"')){
        cout << t << "\n";
    }
    cout << stoi("1234                          ") << "\n";
}