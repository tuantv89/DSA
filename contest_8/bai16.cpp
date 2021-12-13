#include <bits/stdc++.h>
using namespace std;
vector<int> a(6);
vector<int> b(6);
int mini_step()
{
	if (a == b)
		return 0;
	int ans = 0;
	set<vector<int>> checked;
	queue<vector<int>> q;
	q.push(a);
	checked.insert(a);
	while (q.size() > 0)
	{
		ans++;
		int size = q.size();
		while (size--)
		{
			vector<int> tmp = q.front();
			q.pop();
			// for(int i=0;i<6;i++)
			// cout<<tmp[i]<<" ";
			vector<int> left(6);
			left[0] = tmp[3];
			left[1] = tmp[0];
			left[4] = tmp[1];
			left[3] = tmp[4];
			left[2] = tmp[2];
			left[5] = tmp[5];
			// for(int i=0;i<6;i++)
			// cout<<left[i]<<" ";
			// cout<<endl;
			if (left == b)
				return ans;
			if (checked.find(left) == checked.end())
			{
				checked.insert(left);
				q.push(left);
			}
			vector<int> right(6);
			right[0] = tmp[0];
			right[3] = tmp[3];
			right[1] = tmp[4];
			right[2] = tmp[1];
			right[4] = tmp[5];
			right[5] = tmp[2];
			if (right == b)
				return ans;
			if (checked.find(right) == checked.end())
			{
				checked.insert(b);
				q.push(right);
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 0; i < 6; i++)
		cin >> b[i];
	cout << mini_step();
	return 0;
}
