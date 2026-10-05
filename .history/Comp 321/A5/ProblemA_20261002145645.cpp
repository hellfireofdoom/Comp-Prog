#include <iostream>
#include <map>
// #include <ctime>
#include <chrono>
#include <unordered_map>
#include <string>
#include <sstream>


using namespace std;



int main(){
    string line;
    unordered_map<string, int> variables;
    unordered_map<int, string> nums;
    while(getline(cin, line)){
        stringstream ss(line);
        string operation;
        ss >> operation;
        if (operation == "def"){
            string var;
            int value;
            ss >> var >> value;
            variables.insert({var, value});
            nums.insert({value, var});
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
                ss >> op >> operand;

                cout << op << " " << operand << " "; 
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


