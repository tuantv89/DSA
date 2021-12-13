#include <bits/stdc++.h>
using namespace std;

bool help(int remain, vector<int> &nums, int idx)
{
    if (remain == 0)
    {
        return true;
    }

    if (remain < 0)
    {
        return false;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        if (help(remain - nums[idx], nums, i + 1))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        int num;
        cin >> num;
        int sum = 0;
        vector<int> vec;
        for (int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            vec.push_back(temp);
        }
        if (sum % 2 == 1)
            cout << "NO" << endl;
        else
        {
            sort(vec.begin(), vec.end());
            bool temp = help(sum / 2, vec, 0);
            if (temp)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
