#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int countLeast(string word){
    int zero = 0;
    int one = 0;
    for (char c: word){
        if (c == '0') zero++;
        if (c == '1') one++;
    }
    return min(one, zero);
}

int countZero(string word){
    int zero = 0;
    for (char c: word){
        if (c == '0') zero++;
    }
    return zero;
}

int twoPointersSortOperations(string word, int limit){
    
    int l = 0, r = word.length()-1;
    int operations = 0;
    bool flag = false;
    
    while(l < r - 1){
        flag = false;

        if (l < word.length() - 1){
            if (word[l] == '1' && word[l+1] == '0'){
                word[l] = '0';
                l++;
                operations++;

            }
            else if (word[l] == '0'){
                l++;
            }
            
        }
        if (r > 1){
            if (word[r] == '0' && word[r-1] == '1'){
                word[r] = '1';
                r--;
                operations++;
            }
            else if (word[r] == '1'){
                r--;
            }
        }
        if (operations > limit) return limit;

        if (!flag) {
            word[l] = '0';
            word[r] = '1';
            operations += 2;
            l++;
            r--;
        }

    }
    return operations;
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int m;
    string word;
    while (cin >> m >> word){

        int least = countLeast(word);

        // edge case: first character is '1' so need all other chars to be 1
        if (word[0] == '1'){ 
            cout << countZero(word) << "\n"; 


        cout << min(least, twoPointersSortOperations(word, least)) << "\n";
    }
}
}