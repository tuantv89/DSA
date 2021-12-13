#include <bits/stdc++.h>
using namespace std;
int test = 1;
int n, k, sum = 0;
vector<int> a;
vector<int> vis;
void Input()
{
    cin >> n >> k;
    a.resize(n);
    vis.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void Try(int i, int s, vector<int> z)
{
    if (s > sum)
        return;
    if (s == sum && z.size() != 0)
    {
        k--;
        for (auto zz : z)
        {
            vis[zz] = 1;
        }

        return;
    }
    for (int j = i + 1; j < n; j++)
    {
        if (vis[j] == 0)
        {
            z.push_back(j);
            Try(j, s + a[j], z);
            z.pop_back();
        }
    }
}
void Solve()
{
    sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum % k != 0)
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> tmp;
    sum /= k;
    if (*max_element(a.begin(), a.end()) > sum)
    {
        cout << 0 << '\n';
        return;
    }

    Try(-1, 0, tmp);
    cout << (k <= 0) << '\n';
}
int main()
{
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        Input();
        Solve();
    }
    return 0;
}
