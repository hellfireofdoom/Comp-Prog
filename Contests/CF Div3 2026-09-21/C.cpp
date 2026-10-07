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
    int opZerotoOne = 0;
    int opOnetoZero = 0;
    bool flag = false;
    
    while(l < r - 1){
        flag = false;

        if (l < word.length() - 1){
            if (word[l] == '1' && word[l+1] == '0'){
                word[l] = '0';
                l++;
                operations++;
                flag = true;


            }
            else if (word[l] == '0'){
                l++;
                flag = true;

            }
            
        }
        if (r > 1){
            if (word[r] == '0' && word[r-1] == '1'){
                word[r] = '1';
                r--;
                operations++;
                flag = true;
            }
            else if (word[r] == '1'){
                r--;
                flag = true;
            }
        }
        if (operations > limit) return limit;

        // 011000111001
        if (!flag) {
            // turns all 0s into 1s until we encounter a 0
            while (word[l + opZerotoOne] != '0' && l + opZerotoOne < word.length()){
                opZerotoOne++;
            }
            
            // same
            while (word[r - opOnetoZero] != '1' && r - opOnetoZero > 0){
                opOnetoZero++;
            }
            
            l++;
            r--;
        }

    }
    return min({operations, opZerotoOne, opOnetoZero});
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
        cout << "String: " << word << " Least: " << least << "\n";

        // edge case: first character is '1' so need all other chars to be 1
        if (word[0] == '1'){ 
            cout << countZero(word) << "\n"; 
            continue;
        }

        cout << min(least, twoPointersSortOperations(word, least)) << "\n";
    }
}
