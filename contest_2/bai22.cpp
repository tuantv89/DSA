#include <bits/stdc++.h>
#define MAX 100
using namespace std;
vector<string> v;
bool visited[100][100];
string s;
bool isvalid(int i, int j, int n)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
        return true;
    return false;
}
void path(int m[MAX][MAX], int i, int j, int n)
{
    visited[i][j] = true;
    if (i == n - 1 && j == n - 1)
        v.push_back(s);
    if (m[i + 1][j] && isvalid(i + 1, j, n) && !visited[i + 1][j])
    {
        s = s + "D";
        path(m, i + 1, j, n);
        s.pop_back();
        visited[i + 1][j] = false;
    }
    if (m[i][j + 1] && isvalid(i, j + 1, n) && !visited[i][j + 1])
    {
        s = s + "R";
        path(m, i, j + 1, n);
        s.pop_back();
        visited[i][j + 1] = false;
    }
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    v.clear();
    s.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
    path(m, 0, 0, n);
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m[MAX][MAX];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        if (m[0][0] == 0)
            cout << "-1";
        else
        {
            vector<string> result = printPath(m, n);
            if (result.size() == 0)
                cout << -1;
            else
                for (int i = 0; i < result.size(); i++)
                    cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
