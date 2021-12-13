#include <bits/stdc++.h>
using namespace std;
int dp[1000][10005];
int mini(int a, int b)
{
    if (a > b || a < 0 || b < 0 || a > 900 || b > 8100)
        return -1;
    if (a == 0 && b == 0)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];
    int ans = 101;
    for (int i = 9; i >= 1; i--)
    {
        int k = mini(a - i, b - (i * i));
        if (k != -1)
            ans = min(ans, k + 1);
    }
    return dp[a][b] = ans;
}
void Min(int a, int b)
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int k = mini(a, b);
    if (k == -1 || k > 100)
        cout << "-1";
    else
    {
        while (a > 0 && b > 0)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (a >= i && b >= i * i && 1 + dp[a - i][b - i * i] == dp[a][b])
                {
                    cout << i;
                    a -= i;
                    b -= i * i;
                    break;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        Min(a, b);
        cout << endl;
    }
    return 0;
}
