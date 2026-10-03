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
    string s;
    unordered_map<string, int> variables;
    unordered_map<int, string> nums;
    while (cin >> s)
    {
        // stringstream ss(line);
        
        if (s == "def")
        {
            string var;
            int value;
            cin >> var >> value;
            if (variables.count(var)){
                int curValue = variables[var];
                nums.erase(curValue);
            }
            variables[var] = value;
            nums[value] = var;
        }
        else if (s == "calc")
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
                    // cout << "res: " << res;
                }
                else if (op == "-")
                {
                    res -= variables.at(operand);
                    // cout << "res: " << res;

                }
            }
            // cout << "res: " << res << "\n";
            cout << "= ";
            if (flag || !nums.count(res))
            {
                cout << "unknown\n";

            }
            else
            {
                cout << nums[res] << "\n";
            }
        }
        else if (s == "clear")
        {
            variables.clear();
            nums.clear();
        }
    }
}
