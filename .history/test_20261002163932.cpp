#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  string res = "";
  for(int i = 0; i < s.length()-1; i++){
      res += s[i] + 'o';
  }
  res += res[s.length()-1];
  cout << res << "\n";
}