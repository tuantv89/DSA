#include <bits/stdc++.h>
using namespace std;
int m;
void getsoln(vector<vector<int>> &res, vector<int> &temp, vector<int> &a, int i, int sum)
{
    if (sum == 0)
    {
        res.push_back(temp);
        return;
    }
    if (sum < 0)
        return;
    for (int j = i; j < m; j++)
    {
        if (a[j] > sum)
            break;
        temp.push_back(a[j]);
        getsoln(res, temp, a, j, sum - a[j]);
        temp.pop_back();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        vector<int> a;
        int i, j;
        map<int, int> mp;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (mp[x] == 0)
                a.push_back(x);
            mp[x]++;
        }
        m = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        vector<int> temp;
        getsoln(res, temp, a, 0, sum);
        sort(res.begin(), res.end());
        if (res.size() == 0)
            cout << "-1" << endl;
        else
        {
            for (i = 0; i < res.size(); i++)
            {
                cout << "[";
                for (j = 0; j < res[i].size(); j++)
                {
                    if (j == res[i].size() - 1)
                        cout << res[i][j];
                    else
                        cout << res[i][j] << " ";
                }
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
