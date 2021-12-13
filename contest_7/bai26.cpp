#include <bits/stdc++.h>
using namespace std;
void solve(int price[], int n)
{
    int res[n];
    stack<int> st;
    st.push(0);
    res[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        res[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}
int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);
    return 0;
}
