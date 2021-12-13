#include <bits/stdc++.h>
using namespace std;
int first(int n)
{
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}
int Count(int n)
{
    int cnt = 1;
    while (n != 0)
    {
        int l = first(n);
        n -= l;
        cnt++;
    }
    return cnt;
}

int largest(int k)
{
    int left = k;
    int right = k * 10;
    int mid = (left + right) / 2;

    int len = Count(mid);

    while (len != k)
    {
        mid = (left + right) / 2;
        len = Count(mid);
        if (len > k)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    while (len == k)
    {

        if (len != Count(mid + 1))
        {
            break;
        }
        mid++;
    }
    return (mid);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        cout << largest(k) << endl;
    }
    return 0;
}
