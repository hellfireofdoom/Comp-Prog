#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    cin.ignore();
    map<string, ll> toReadList;
    priority_queue<pair<ll, pair<string, ll>>, vector<pair<ll, pair<string, ll>>, greater<ll>> toBeAdded;
    while (n--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        string title;
        ll pages;
        getline(ss, token, '"');
        getline(ss, token, '"');
        title = token;
        getline(ss, token, '"');

        pages = stoll(token);

        // cout << "title: " << title << "\n";
        if (title.compare("Jane Eyre") < 0)
        {
            toReadList.insert({title, pages});
        }
    }
    while (m--)
    {

        ll toBeAddedTime;
        string title;
        ll pages;

        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;        

        ss >> toBeAddedTime;

        getline(ss, token, '"');
        getline(ss, token, '"');
        title = token;

        ss >> pages;


        toBeAdded.push(pair(toBeAddedTime, pair(title, pages)));
    }
    ll timeElapsed = 0;
    while (!toReadList.empty())
    {
        timeElapsed += toReadList.begin()->second;   // Add time
        // cout << "Added time: " << toReadList.begin()->second << "\n";
        // cout << "Time Elapsed: " << timeElapsed << "\n";
        // cout << "Title: " << toReadList.begin()->first << "\n";

        toReadList.erase(toReadList.begin()->first); // Remove first book to read
        // cout << "Time of next to add: " << toBeAdded.front().first << "\n"; 
        // cout << timeElapsed << "\n";
        // cout << toBeAdded.front().first << "\n";
        while (!toBeAdded.empty() && toBeAdded.top().first <= timeElapsed)
        {
            
            
            const auto [title, pages] = toBeAdded.top().second;
            toBeAdded.pop();

            if (title.compare("Jane Eyre") <= 0)
            {
                toReadList.insert({title, pages});
            }

        }
    }
    timeElapsed += k;
    cout << timeElapsed << "\n";
}