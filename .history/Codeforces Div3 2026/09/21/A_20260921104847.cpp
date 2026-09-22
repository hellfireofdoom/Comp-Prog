#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int partNum;
    for (int i = 0; i < n; i++){
        cin >> partNum;
        int minWeak = partNum;
        int k;
        for(int j = 0; j < 3; j++){
            cin >> k;
            minWeak = min(minWeak, partNum - k);
        }
        cout << "Hi" << minWeak << "\n";
    }
}