#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
bool ngoac(char c)
{
    return ((c == '(') or (c == ')'));
}
bool compare(string x, string y)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (int(x[i]) == int(y[i]))
            continue;
        return (int(x[i]) < int(y[i]));
    }
}

bool check(string str)
{
    if (str.empty())
        return false;
    if (str.length() == 1 && !ngoac(str[0]))
        return false;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;
        if (cnt < 0)
            return false;
    }
    return (cnt == 0);
}

void solve()
{
    vector<string> res;
    string str;
    cin >> str;
    if (str.empty())
    {
        cout << "-1" << endl;
        return;
    }
    if (str.length() == 1 and !ngoac(str[0]))
    {
        cout << "-1" << endl;
        return;
    }
    set<string> visit;
    queue<string> q;
    bool found = false;
    int maxLength = INT_MIN;
    q.push(str);
    visit.insert(str);
    while (!q.empty())
    {
        string str1 = q.front();
        q.pop();
        if (check(str1))
        {

            if (!found)
            {

                maxLength = str1.size();
                res.push_back(str1);
                found = true;
            }
            else
            {

                if (str1.size() == maxLength)
                {
                    res.push_back(str1);
                }
            }
        }
        if (found)
            continue;
        for (int i = 0; i < str1.length(); i++)
        {
            if (!ngoac(str1[i]))
                continue;
            string temp = str1.substr(0, i) + str1.substr(i + 1);
            if (visit.find(temp) == visit.end())
            {
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
    if (found == false)
        cout << "-1";
    else
    {
        sort(res.begin(), res.end(), compare);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
