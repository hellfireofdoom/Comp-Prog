#include <iostream>
#include <map>
// #include <ctime>
#include <chrono>
#include <unordered_map>
#include <string>
#include <sstream>


using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(){
    string line;
    unordered_map<string, int, custom_hash> variables;
    unordered_map<int, string, custom_hash> nums;
    while(getline(cin, line)){
        stringstream ss(line);
        string operation;
        ss >> operation;
        if (operation == "def"){
            int var;
            int value;
            ss >> var >> value;
            variables.insert(var, value);
            nums.insert(value, var);
        }
        else if (operation == "calc"){
            int res = 0;
            bool flag = false;

            string operand;
            ss >> operand;
            if(variables.count(operand)) res += variables[operand], flag = true;
            cout << operand << " ";

            string op;

            

            

            while(ss.rdbuf()->in_avail() != 0){
                ss >> operand >> op;

                cout << operand << " " << op << " "; 
                if(!variables.count(operand)){
                    flag = true;
                }
                else if (op == "+"){
                    res += variables[operand];
                }
                else if (op == "-"){
                    res -= variables[operand];
                }
            }
            if (flag || !nums.count(res)) cout << "unknown\n";
            else{
                cout << nums[res] << "\n";
            }
            


        }
        else if (operation == "clear"){
            variables.clear();
            nums.clear();
        }

    }
}


