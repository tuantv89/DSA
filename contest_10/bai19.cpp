#include <bits/stdc++.h>
using namespace std;
#define MAX 505
bool isvalid(int x, int y, int n, int m)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return true;
    }
    return false;
}
void Min(int a[MAX][MAX], int n, int m)
{
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    map<pair<int, int>, int> dist;
    for (int i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            dist[make_pair(i, j)] = INT_MAX;
        }
    }
    set<pair<int, pair<int, int>>> s;
    s.insert(make_pair(a[1][1], make_pair(1, 1)));
    dist[make_pair(1, 1)] = a[1][1];
    while (!s.empty())
    {
        pair<int, pair<int, int>> p = *(s.begin());
        int weight = p.first;
        pair<int, int> tmp = p.second;
        s.erase(s.begin());
        for (int i = 0; i < 4; i++)
        {
            int x1 = tmp.first + dx[i];
            int y1 = tmp.second + dy[i];
            if (isvalid(x1, y1, n, m))
            {
                if (weight + a[x1][y1] < dist[make_pair(x1, y1)])
                {
                    auto l = s.find(make_pair(dist[make_pair(x1, y1)], make_pair(x1, y1)));
                    if (l != s.end())
                    {
                        s.erase(l);
                    }
                    s.insert(make_pair(weight + a[x1][y1], make_pair(x1, y1)));
                    dist[make_pair(x1, y1)] = weight + a[x1][y1];
                }
            }
        }
    }
    cout << dist[make_pair(n, m)] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        int a[MAX][MAX];
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        Min(a, n, m);
    }
    return 0;
}
