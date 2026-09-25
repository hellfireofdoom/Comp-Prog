#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        const long long MX = 101;
        vector<long long> freq(MX);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }

        // vector<long long> res{};
        int counter = 0;
        while(counter < n){
            for(int i = MX-1; i >= 0; i--){
                if (freq[i]) {
                    cout << i << " ";
                    freq[i]--;
                    counter++;
                }
            }
        }
        cout << endl;
    }
}