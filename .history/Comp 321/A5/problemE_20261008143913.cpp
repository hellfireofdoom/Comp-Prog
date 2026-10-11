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
    cin.ignore();
    map<string, ll> toReadList;
    queue<pair<int, pair<string, int>>> toBeAdded;
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

        pages = stoi(token);


        if (title < "\"Jane Eyre\"")
        {
            toReadList.insert({title, pages});
        }
    }
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
        toBeAddedTime = stoi(token);

        getline(ss, token, '"');
        title = token;

        getline(ss, token, '"');
        pages = stoi(token);


        toBeAdded.push(pair(toBeAddedTime, pair(title, pages)));
    }
    ll timeElapsed = 0;
    while (!toReadList.empty())
    {
        timeElapsed += toReadList.begin()->second;   // Add time
        cout << timeElapsed << "\n";
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