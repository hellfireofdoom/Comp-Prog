#include <bits/stdc++.h>
using namespace std;

struct Node{
    int visits = 0;
    Node* alphabet[26];

    Node(){
        for(int i = 0; i < 26; i++){
            alphabet[i] = nullptr;
        }
    }
};

void insertWord(Node* root, string word){
    Node* cur = root;
    for(char c: word){
        if (cur->alphabet[c - 'a'] == nullptr){
            cur->alphabet[c - 'a'] = new Node();
        }
        cur = cur->alphabet[c - 'a'];
        cur->visits = cur->visits + 1;
    }
    cout << cur->visits - 1 << "\n";
}

void solve(Node* root){
    string word;
    cin >> word;
    // cout << word << "\n";  
    insertWord(root, word);
}


int main(){
    int n;
    cin >> n;
    Node* root = new Node();
    while(n--){
        // cout << n << "\n";
        solve(root);
    }
}
