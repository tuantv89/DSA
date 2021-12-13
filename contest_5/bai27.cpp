#include <bits/stdc++.h>
using namespace std;
int DP[1005][1005];
int maximum(int n, int val[], int w[], int V)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (w[i - 1] <= j)
                DP[i][j] = max(val[i - 1] + DP[i - 1][j - w[i - 1]], DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[n][V];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, V;
        cin >> n;
        cin >> V;
        int val[n], w[n];
        for (int i = 0; i < n; i++)
            cin >> w[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];
        cout << maximum(n, val, w, V) << endl;
    }
    return 0;
}
