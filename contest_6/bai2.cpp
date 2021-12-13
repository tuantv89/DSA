#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        vector<pair<int, int>> vect;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
            vect.push_back(make_pair(abs(x - k), i));
        }
        sort(vect.begin(), vect.end());
        for (int i = 0; i < n; i++)
        {
            cout << v[vect[i].second] << " ";
        }
        cout << endl;
    }
    return 0;
}
