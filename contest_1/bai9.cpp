#include <bits/stdc++.h>
using namespace std;
void generateCode(int N)
{
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    int n = N, size = 2;
    while (n > 1)
    {
        int s = size - 1;
        while (s >= 0)
        {
            v.push_back(v[s]);
            s--;
        }
        int half = size;
        size *= 2;
        for (int i = 0; i < half; i++)
        {
            v[i] = "0" + v[i];
        }
        for (int i = half; i < size; i++)
            v[i] = "1" + v[i];
        n--;
    }
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        generateCode(n);
        cout << endl;
    }
    return 0;
}
