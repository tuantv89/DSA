#include <bits/stdc++.h>
using namespace std;
void cong(string a, string b, int k)
{

	while (a.length() != b.length())
	{
		if (a.length() < b.length())
			a = "0" + a;
		else
			b = "0" + b;
	}
	string ans = "";
	int temp, nho = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		temp = (a[i] - '0') + (b[i] - '0') + nho;
		nho = temp / k;
		temp %= k;
		ans = (char)(temp + '0') + ans;
	}
	if (nho == 1)
		cout << "1";
	cout << ans << endl;
}
int main()
{
	int k;
	string a, b;
	cin >> k >> a >> b;
	cong(a, b, k);
	return 0;
}
