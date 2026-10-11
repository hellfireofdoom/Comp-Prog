#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string s = "\"Hello\" Your mom";
    getline(cin, s);
    stringstream ss(s);
    string t;
    while(getline(ss, t, '"')){
        cout << t << "\n";
    }
    cout << stoi("1234                          ") << "\n";
}