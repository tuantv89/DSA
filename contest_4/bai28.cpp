#include <bits/stdc++.h>
using namespace std;

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
        sort(a, a + n);
        int res = n, mid = n / 2;
        for (int i = 0; i < n / 2 && mid < n; i++)
        {
            while (mid < n)
            {
                if (2 * a[i] <= a[mid])
                {
                    res--;
                    mid++;
                    break;
                }
                else
                    mid++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
