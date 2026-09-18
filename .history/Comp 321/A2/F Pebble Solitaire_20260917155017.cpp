#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minPebbles = 12;

// A B C   oo- 
// AXC
// 35 or 53

string applyMove(string state, int move){
    string newState = state;

    int A, B, C;
    A = move/10;
    C = move%10;
    B = (A + C) / 2;

    newState[A] = newState[B] = '-';
    newState[C] = 'o';
    
    return newState; 
}

vector<int> getMoves(string state){
    vector<int> moves(0);
    for (int i = 0; i < state.length(); i++){
        if (i + 2 < state.length()){
            // oo-
        if(state[i] == state[i+1] == 'o' && state[i+2] == '-'){
            moves.push_back(i*10 + (i+2));
        }
    }
    if (i - 2 >= 0){
        // -oo
        if (state[i-2] == '-' && state[i-1] == state[i] == 'o'){
            moves.push_back(i*10 + (i-2));
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
        return;
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