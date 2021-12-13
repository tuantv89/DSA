#include <bits/stdc++.h>
using namespace std;
int dp[1005], a[1005], n;
int tinh()
{
    for (int i = 0; i < 1005; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && (dp[j] + 1) > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (ans < dp[i])
            ans = dp[i];
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res = n - tinh();
        cout << res << endl;
    }
    return 0;
}
