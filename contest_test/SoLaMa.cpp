#include <bits/stdc++.h>
using namespace std;
int value(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else if (c == 'M')
        return 1000;
    return -1;
}
int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n, i, ans = 0, x, y;
        n = s.length();
        for (i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                x = value(s[i]);
                ans += x;
            }
            else
            {
                x = value(s[i]);
                y = value(s[i + 1]);
                if (x >= y)
                    ans += x;
                else
                    ans -= x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
