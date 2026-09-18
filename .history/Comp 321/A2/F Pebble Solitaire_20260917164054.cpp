#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int minPebbles = 12;

// A B C   oo- 
// AXC
// 35 or 53

string applyMove(string state, int move){
    string newState = state;

    int A, B, C;
    if (move == 810 || move == 911){
        A = move / 100;
        C = move % 100;
    }
    else{
    A = move/10;
    C = move%10;
    }
    B = (A + C) / 2;

    newState[A] = newState[B] = '-';
    newState[C] = 'o';
    
    return newState; 
}

//If the second position is >= 10, then
vector<int> getMoves(string state){
    vector<int> moves(0);
    for (int i = 0; i < state.length(); i++){
        int f = 1;
        if (i + 2 < state.length()){
            // oo-
        if(state[i] == 'o' && state[i+1] == 'o' && state[i+2] == '-'){
            //911, 810
            if (i+2 >= 10  ){
                f=10;
            }
            moves.push_back(f*i*10 + (i+2));
        }
    }
    if (i - 2 >= 0){

        // -oo
        if (state[i-2] == '-' && state[i-1] == 'o' && state[i] == 'o'){
            //119, 108
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
        // cout <<"Final state: " << state << "\n";
        return;
    }
    string newState = applyMove(state, moves.back());
    moves.pop_back();
    search(newState, getMoves(newState));

    search(state, moves);
}




int main(){
    // string state = "oooooooooo-o";
    // cout << "minPebbles: " << minPebbles << "\n";
    // for (int move : getMoves(state)){
    //     cout << "Move: " << move << "\n"; 
    // }

    // search(state, getMoves(state));
    // cout << "minPebbles: " << minPebbles << "\n";


    int n;
    ifstream TestFile("Ftestcase.txt");
    
    TestFile >> n;
    string line;
    for(int i = 0; i < n; i++){
        cin >> line;
        minPebbles = 12;
        search(line, getMoves(line));
        cout << minPebbles << "\n";
    }

}