#include <bits/stdc++.h>
using namespace std;
char flip(char a)
{
    return (a == '0') ? '1' : '0';
}

void grayToBin(string gray)
{
    string bin = "";
    bin += gray[0];

    for (int i = 1; i < gray.length(); i++)
    {
        if (gray[i] == '0')
            bin += bin[i - 1];
        else
            bin += flip(bin[i - 1]);
    }
    cout << bin;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string gray;
        cin >> gray;
        grayToBin(gray);
        cout << endl;
    }
    return 0;
}
