#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cur, next;
    cin >> cur;
    n--;
    bool flag = true;
    while (n--){
        cin >> next;
        if (next < 2* cur) {
           flag = false; break;
        }
     cur = next;
     
    }
    if (flag) cout << "canonical\n";
    else{
        cout << "non-canonical\n";
    }
}