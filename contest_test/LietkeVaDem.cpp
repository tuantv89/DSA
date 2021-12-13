#include <bits/stdc++.h>
using namespace std;
map<int, int> so, vt;
vector<pair<int, pair<int, int>>> day;
int cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first < b.first;
}
int check(int a)
{
	while (a)
	{
		int temp = a % 10;
		if (temp != 2 && temp != 3 && temp != 5 && temp != 7)
			return 0;
		a /= 10;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int s, temp = 1;
	while (cin >> s)
	{
		if (check(s))
		{
			if (so[s] == 0)
			{
				so[s] = 1;
				vt[s] = temp++; // vi tri xuat hien dau tien
			}
			else
				so[s]++; // so lan xuat hien
		}
	}
	for (map<int, int>::iterator i = so.begin(); i != so.end(); i++)
	{
		day.push_back(make_pair(vt[i->first], make_pair(i->first, i->second))); // vitri - gia tri - so lan xuat hien
	}
	sort(day.begin(), day.end(), cmp);
	for (int i = 0; i < day.size(); i++)
	{
		pair<int, int> temp = day[i].second;
		cout << temp.first << " " << temp.second << endl;
	}
	return 0;
}
