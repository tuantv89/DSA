#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 10005
vector<ll> dp;
void ugly()
{
    dp.push_back(1);
    ll i2 = 0, i3 = 0, i5 = 0;
    ll n2 = 2, n3 = 3, n5 = 5;
    ll i, minn;
    for (i = 1; i < M; i++)
    {
        minn = min(min(n2, n3), n5);
        dp.push_back(minn);
        if (minn == n2)
        {
            i2 += 1;
            n2 = dp[i2] * 2;
        }
        if (minn == n3)
        {
            i3 += 1;
            n3 = dp[i3] * 3;
        }
        if (minn == n5)
        {
            i5 += 1;
            n5 = dp[i5] * 5;
        }
    }
    // set<int> s;
    // s.insert(1);
    // vector<int> v;
    // while (v.size() < 10000)
    // {
    //     auto it = *s.begin();
    //     v.push_back(it);
    //     s.insert(it * 2);
    //     s.insert(it * 3);
    //     s.insert(it * 5);
    //     s.erase(s.begin());
    // }
    // for (int i = 0; i < 10000; i++)
    // {
    //     if (dp[i] != v[i])
    //     {
    //         cout << "NO" << endl;
    //         cout << i << " " << dp[i] << " " << v[i] << endl;
    //         return;
    //     }
    // }
    // cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    ugly();
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n - 1] << endl;
    }
    return 0;
}
