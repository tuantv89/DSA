#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max_hcn(ll a[], int n)
{
    stack<int> st;
    int top;
    ll s_top, ans = 0;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || a[st.top()] <= a[i])
            st.push(i++);
        else
        {
            top = st.top();
            st.pop();
            s_top = a[top] * (st.empty() ? i : i - st.top() - 1);
            if (ans < s_top)
                ans = s_top;
        }
    }
    while (!st.empty())
    {
        top = st.top();
        st.pop();
        s_top = a[top] * (st.empty() ? i : i - st.top() - 1);
        if (ans < s_top)
            ans = s_top;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << max_hcn(a, n) << endl;
    }
    return 0;
}
