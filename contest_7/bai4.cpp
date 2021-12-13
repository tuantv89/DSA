#include <bits/stdc++.h>
using namespace std;
bool is_ok(string s)
{
    int n = s.length();
    stack<char> st;
    char c;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }
        if (st.empty())
            return false;
        else if (s[i] == ')')
        {
            c = st.top();
            st.pop();
            if (c != '(')
                return false;
        }
        else if (s[i] == '}')
        {
            c = st.top();
            st.pop();
            if (c != '{')
                return false;
        }
        else if (s[i] == ']')
        {
            c = st.top();
            st.pop();
            if (c != '[')
                return false;
        }
    }
    return st.empty();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (is_ok(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
