#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> c;
#define Max 9999999
int n, soto = 0;
int fopt = Max;
int s;
int size = 0;
void Try(int i)
{
	for (int j = 1; j >= 0; j--)
	{
		soto += j;
		s -= (j * c[i]);
		if (s == 0)
			fopt = min(fopt, soto);
		else if (i < size && soto + 1 < fopt && s > 0)
			Try(i + 1);
		soto -= j;
		s += (j * c[i]);
	}
}
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		// vector<int>::iterator it=find(c.begin(),c.end(),x);
		// if(it==c.end())
		c.push_back(x);
	}
	size = c.size() - 1;
	sort(c.begin(), c.end(), greater<int>());
	Try(0);
	if (fopt != Max)
		cout << fopt;
	else
		cout << "-1";
	return 0;
}
