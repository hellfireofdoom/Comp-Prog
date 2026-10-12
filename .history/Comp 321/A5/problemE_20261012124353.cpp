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

struct IncomingBook
{
    ll t;
    string title;
    ll pages;

    bool operator>(const IncomingBook &other)
    {
        return t > other.t;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    cin.ignore();
    map<string, ll> toReadList;
    priority_queue<IncomingBook, vector<IncomingBook>, greater<IncomingBook>> toBeAdded;
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
        if (title < "Jane Eyre")
        {
            toBeAdded.push(IncomingBook{toBeAddedTime, title, pages});
        }
    }
    ll timeElapsed = 0;
    while (!toReadList.empty())
    {
        auto it = toReadList.begin();
        timeElapsed += it->second; // Add time

        toReadList.erase(it->first); // Remove first book to read

        while (!toBeAdded.empty() && toBeAdded.top().t <= timeElapsed)
        {

            toReadList[toBeAdded.top().title] = toBeAdded.top().pages; // add to toreadlist

            toBeAdded.pop();
        }
    }
    timeElapsed += k;
    cout << timeElapsed << "\n";
}