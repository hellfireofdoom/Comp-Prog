#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> visited;

int main(){
    cout << visited.max_size() << endl;

}