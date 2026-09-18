#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;
    string word;
    for (int i = 0; i < n; i++){
        cin >> word;
        int x = word.length();
        if (x > 10){
            cout << word[0] << x-2 << word[x-1] << "\n"; 
        }
        else{
            cout << word << "\n";
        }
    }
}