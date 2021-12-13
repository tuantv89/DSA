#include <bits/stdc++.h>
using namespace std;
int maxx(int a[], int n)
{
    int ans = INT_MIN;
    int sum[n];
    copy(a, a + n, sum);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && sum[i] < sum[j] + a[i])
                sum[i] = sum[j] + a[i];
        }
    }
    int sum2[n];
    copy(a, a + n, sum2);
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j] && sum2[i] < sum2[j] + a[i])
                sum2[i] = sum2[j] + a[i];
        }
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, sum[i] + sum2[i] - a[i]);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxx(a, n) << endl;
    }
    return 0;
}
