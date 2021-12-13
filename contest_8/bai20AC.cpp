#include <bits/stdc++.h>
using namespace std;
struct hexg
{
    int h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
};
int ans = INT_MAX;
hexg a;
bool check(hexg x)
{
    if ((x.h0 == 1) && (x.h1 == 2) && (x.h2 == 3) && (x.h3 == 8) && (x.h4 == 0) && (x.h5 == 0) && (x.h6 == 4) && (x.h7 == 7) && (x.h8 == 6) && (x.h9 == 5))
        return true;
    return false;
}
hexg latPhai(hexg x)
{
    int tmp = x.h1;
    x.h1 = x.h4;
    x.h4 = x.h8;
    x.h8 = x.h9;
    x.h9 = x.h6;
    x.h6 = x.h2;
    x.h2 = tmp;
    return x;
}
hexg latTrai(hexg x)
{
    int tmp = x.h0;
    x.h0 = x.h3;
    x.h3 = x.h7;
    x.h7 = x.h8;
    x.h8 = x.h5;
    x.h5 = x.h1;
    x.h1 = tmp;
    return x;
}

void dfs(hexg x, int buoc)
{
    if (check(x))
    {
        ans = min(ans, buoc);
        return;
    }
    else
    {
        if (buoc >= 25)
            return;
        dfs(latTrai(x), buoc + 1);
        dfs(latPhai(x), buoc + 1);
    }
}
int main()
{
    cin >> a.h0 >> a.h1 >> a.h2;
    cin >> a.h3 >> a.h4 >> a.h5 >> a.h6;
    cin >> a.h7 >> a.h8 >> a.h9;
    dfs(a, 0);
    cout << ans;
}
