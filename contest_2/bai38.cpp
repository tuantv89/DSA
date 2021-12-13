#include <bits/stdc++.h>
using namespace std;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
typedef unsigned long long int ull;
#define Max 10000000000000000000
ull ans = Max;
ull poww(int a, int b)
{
	ull answer = 1;
	for (int i = 1; i <= b; i++)
		answer *= a;
	return answer;
}
int s[1005];
void sang()
{
	s[0] = 0;
	s[1] = 0;
	for (int i = 2; i <= 1000; i++)
		s[i] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		if (s[i])
		{
			for (int j = i * 2; j <= 1000; j += i)
				s[j] = 0;
		}
	}
}
void getsoln(vector<int> &temp, int i, int remain)
{
	if (remain == 1)
	{
		ull tich = 1;
		for (int k = 0; k < temp.size(); k++)
		{
			ull tich1 = poww(p[k], temp[k]);
			if (tich1 > Max / tich)
			{
				tich = -1;
				break;
			}
			tich *= tich1;
		}
		if (tich != -1)
			ans = min(ans, tich);
		return;
	}
	if (remain <= 0)
		return;
	for (int j = i; j >= 2; j--)
	{
		if (j > remain)
			continue;
		if (remain % j == 0)
		{
			temp.push_back(j - 1);
			getsoln(temp, j, remain / j);
			temp.pop_back();
		}
	}
}
int main()
{
	int t;
	cin >> t;
	sang();
	while (t--)
	{
		ans = Max;
		int n;
		cin >> n;
		if (n == 1)
			cout << "1" << endl;
		else if (n == 2)
			cout << "2" << endl;
		else if (s[n] && n <= 63)
			cout << poww(2, n - 1) << endl;
		else
		{
			vector<int> temp;
			getsoln(temp, 63, n);
			if (ans != Max)
				cout << ans << endl;
		}
	}
	return 0;
}
