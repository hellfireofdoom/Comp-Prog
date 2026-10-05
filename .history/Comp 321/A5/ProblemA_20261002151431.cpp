#include <iostream>
#include <map>
// #include <ctime>
#include <chrono>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string line;
    unordered_map<string, int> variables;
    unordered_map<int, string> nums;
    while (getline(cin, line))
    {
        stringstream ss(line);
        string operation;
        ss >> operation;
        if (operation == "def")
        {
            string var;
            int value;
            ss >> var >> value;
            variables.insert({var, value});
            nums.insert({value, var});
        }
        else if (operation == "calc")
        {
            int res = 0;
            bool flag = false;

            string operand;
            ss >> operand;
            if (variables.count(operand))
                res += variables[operand];
            else{
                flag = true;
            }
            cout << operand << " ";

            string op;

            while (ss.rdbuf()->in_avail() != 0)
            {
                ss >> op >> operand;
                if (op == "=")
                    break;

                cout << op << " " << operand << " ";
                if (!variables.count(operand))
                {
                    // cout << "unknown variable name: " << operand << "\n";
                    flag = true;
                }
                else if (op == "+")
                {
                    res += variables.at(operand);
                }
                else if (op == "-")
                {
                    res -= variables.at(operand);
                }
            }
            // cout << "res: " << res << "\n";
            cout << "= ";
            if (flag)
            {
                cout << "unknown\n";
                // cout << "flag: " << flag << "\n";

            }
            else
            {
                cout << nums[res] << "\n";
            }
        }
        else if (operation == "clear")
        {
            variables.clear();
            nums.clear();
        }
    }
}
