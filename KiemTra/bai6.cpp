#include <bits/stdc++.h>
using namespace std;
int subseq(string str)
{
    int n = str.size();
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        a[i][i] = 1;
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (str[i] == str[j] && k == 2)
            {
                a[i][j] = 2;
            }
            else if (str[i] == str[j])
            {
                a[i][j] = a[i + 1][j - 1] + 2;
            }
            else
            {
                a[i][j] = max(a[i][j - 1], a[i + 1][j]);
            }
        }
    }
    return a[0][n - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << str.size() - subseq(str) << endl;
    }
}
