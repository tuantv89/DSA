#include <bits/stdc++.h>
using namespace std;
int longest_increasing_subsequence(int a[], int n)
{
    int lis[n];
    fill(lis, lis + n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << longest_increasing_subsequence(a, n) << endl;

    return 0;
}
