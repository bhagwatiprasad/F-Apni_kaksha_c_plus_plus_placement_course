#include <bits/stdc++.h>
using namespace std;

int hexaDecToDec(string n)
{
    int ans = 0;
    int x = 1;
    int s = n.size();
    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x * (n[i] - 'A' + 10);
        }
        x *= 16;
    }
    return ans;
}

string decToBase(int n, int b);
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // string s;
    int s, b;
    cin >> s >> b;
    cout << decToBase(s, b);
    return 0;
}

string decToBase(int n, int b)
{
    int x = 1;
    int quotient;
    int base = b;
    char flag = 's';
    if (base >= 9)
        flag = 'l';
    while (n >= x)
    {
        x *= base;
    }
    x /= base;
    string resultS = "";
    int resultN = 0;
    while (x > 0)
    {
        if (flag == 's')
            resultN = resultN * 10;
        quotient = n / x;
        if (flag == 'l')
        {
            if (quotient < 10)
                resultS += to_string(quotient);
            else
            {
                char c = 'A' + quotient - 10;
                resultS.push_back(c);
            }
        }
        n = n % x;
        x /= base;
        if (quotient != 0)
            resultN += quotient;
    }
    if (flag == 's')
        return to_string(resultN);
    else
        return resultS;
}
