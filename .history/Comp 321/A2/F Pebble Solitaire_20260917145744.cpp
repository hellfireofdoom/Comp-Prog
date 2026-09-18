#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minPebbles = 0;

string applyMove(string state, int move){
    
}

vector<int> getMoves(string state){
    
}

int countPebbles(string state){
    int count = 0;
    for(char c : state){
        if (c == '0') count++;
        return count;
    }
}

void search(string state, vector<int> moves){
    if (moves.empty()){ 
        minPebbles = min(countPebbles(state), minPebbles);
    }
    string newState = applyMove(state, moves.back());
    moves.pop_back();
    search(newState, getMoves(newState));

    search(state, moves);
}




int main(){
    
}