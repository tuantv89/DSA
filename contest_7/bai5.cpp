#include <bits/stdc++.h>
using namespace std;
int maxx(string s)
{
    int n = s.length(), ans = INT_MIN;
    if (n == 0)
        return 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (!st.empty())
            {
                ans = max(ans, i - st.top());
            }
            else
                st.push(i);
        }
    }
    if (ans != INT_MIN)
        return ans;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << maxx(s) << endl;
    }
    return 0;
}
