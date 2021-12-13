#include <bits/stdc++.h>
using namespace std;
int dp[10005];
string s;
int n;
int tinh()
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        if (s[i - 1] != '0')
            dp[i] = dp[i - 1];
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
            dp[i] += dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.length();
        if (s[0] == '0')
        {
            cout << 0 << endl;
            continue;
        }
        else
            cout << tinh() << endl;
    }
    return 0;
}
