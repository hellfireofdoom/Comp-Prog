#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solve(){
    int N;
    string inputs;
    cin >> N >> inputs;
    stack<int>memory;
    vector<bool> printed(N+1, false);
    int notPrinted = N;
    for(int i = 1; i <= N; i++){
        int curr = inputs[i-1];
        if (curr == '1'){
            memory.push(i);
        }
        else if (curr == '2'){
            if(!memory.empty()){
                int indexToPrint = memory.top();
                memory.pop();
                printed[indexToPrint] = true;
                notPrinted--;
            }
            else{
                printed[i] = true;
                notPrinted--;
            }
        }else if (curr == '3'){
            printed[i] = true;
            notPrinted--;
            
        }
    }
    cout << notPrinted << "\n";
    for(int i = 1; i <= N; i++){
        if(!printed[i]){
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}