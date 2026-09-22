#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long count = 0;

long long findLargestDenomination(string num){

    if (num[num.length()-1] > 1 ) return log10(num.length());
    else if (num[num.length()-1] == 1){
        if (num.substr(0, num.length()-1).find("0") == string::npos) return log10(num.length());
        else{
            return log10(num.length()-1);
        }
    }

}

bool subtract(string num, long long n){



    string res = ""; // In reverse order, to avoid trailing zeros
    while (num[num.length()-1] != 0 ){
        for (auto i = num.begin(); i < num.end(); i++){
            if (*i == '0'){
                res += '9';
                i++;
                // if more than one zero, e.g. --200000--
                while(*i == '0'){
                    res += '8';
                    i++;
                }
                res += ((*i - '0') - 2) + '0'; // char -> int - 1 -> char
            }
            else{
                res += ((*i - '0') - 1) + '0';                                                                                                                               
            
            }


        }


    }    




}


int main(){

    string num;
    cin >> num;

    subtract(num, findLargestDenomination(num));



}