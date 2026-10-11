#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<string, ll> toReadList;
    queue<pair<int, pair<string, int>>> toBeAdded;
    cout << "n\n";
    while (n--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        string title;
        int pages;
        getline(ss, token, '"');
        getline(ss, token, '"');
        title = token;
        getline(ss, token, '"');
        cout << "stoi" << "\n";

        // pages = stoi(token);
        pages = 1;


        if (title < "\"Jane Eyre\"")
        {
            toReadList.insert({title, pages});
        }
    }
    cout << "m\n";
    while (m--)
    {

        int toBeAddedTime;
        string title;
        int pages;

        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;        
        getline(ss, token, '"');
        // toBeAddedTime = stoi(token);
        toBeAddedTime = 1;
        cout << "stoi1" << "\n";

        getline(ss, token, '"'), title = token;

        getline(ss, token, '"');
        pages = stoi(token);
        cout << "stoi2" << "\n";


        toBeAdded.push(pair(toBeAddedTime, pair(title, pages)));
    }
    ll timeElapsed = 0;
    while (!toReadList.empty())
    {
        timeElapsed += toReadList.begin()->second;   // Add time
        toReadList.erase(toReadList.begin()->first); // Remove first book to read
        if (!toBeAdded.empty() && toBeAdded.front().first <= timeElapsed)
        {
            const auto &[title, pages] = toBeAdded.front().second;
            toBeAdded.pop();
            if (title < "\"Jane Eyre\"")
            {
                toReadList.insert({title, pages});
            }
        }
    }
    timeElapsed += k;
    cout << timeElapsed << "\n";
}