#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minPebbles = 0;

// A B C   --0 or 0--

string applyMove(string state, int move){

    int A, B, C;
    A = move/10;
    C = move%10;
    B = (A + C) / 2;
    if (A < C){
    state[A] = state[B] = '-';
    state[C] = 'o';
    }
    else if (A < C){
        state[A] = state[B] = '-';
        state[C] = 'o';
    }
    return state; 
}

vector<int> getMoves(string state){
    vector<int> moves;
    for (int i = 0; i < state.length(); i++){
        if (i + 2 < state.length()){
        if(state[i] == state[i+1] == 'o' && state[i+2] == '-'){
            moves.push_back(i*10 + (i+2));
        }
    }
    if (i - 2 >= 0){
        if (state[i-2] == '-' && state[i-1] == state[i] == 'o'){
            moves.push_back((i-2)*10 + i);
        }
    }

    }
    return moves;
    
}

int countPebbles(string state){
    int count = 0;
    for(char c : state){
        if (c == 'o') count++;
    }
        return count;

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
    string state = "oooooooooo-o";
    cout << "minPebbles: " << minPebbles << "\n";
    search(state, getMoves(state));
    cout << "minPebbles: " << minPebbles << "\n";

}