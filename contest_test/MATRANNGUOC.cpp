#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, t, a[21][21], d, u;
    int gt;
    cin >> u;
    int dem = 1;
    while (u--)
    {
        cin >> n;
        d = n;
        gt = n * n, t = 1;
        while (gt > 0)
        {
            for (i = t; i <= d; i++) // gan gia tri tu trai sang phai
            {
                a[t][i] = gt;
                gt--;
            }
            for (i = t + 1; i <= d; i++) // tu tren xuong
            {
                a[i][d] = gt;
                gt--;
            }
            for (i = d - 1; i >= t; i--) // tu phai qua trai
            {
                a[d][i] = gt;
                gt--;
            }
            for (i = d - 1; i >= t + 1; i--) // tu duoi len tren
            {
                a[i][t] = gt;
                gt--;
            }
            t++; //
            d--; // dieu kien thu nho xoan oc
        }
        cout << "Test " << dem << ":" << endl;
        for (int p = 1; p <= n; p++)
        {
            for (int q = 1; q <= n; q++)
                cout << a[p][q] << " ";
            cout << endl;
        }
        dem++;
    }
    return 0;
}
