#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;


typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int dup(string num)
{
    int len = num.length();
    for (int i = 1; i < len; i++)
    {
        if (num[i] == num[i - 1])
            return i;
    }
    return 0;
}

void add(string& num, int pos)
{
    int extra = 1;
    for (int i = pos + 1; i < num.size(); i++)
    {
        num[i] = '0';
    }

    while (pos >= 0 && extra)
    {
        int now = (num[pos] - '0') + extra;
        extra = now / 10;
        now = now % 10;

        num[pos] = '0' + now;
        pos--;
    }
    if (pos == -1 && extra)
        num = "1" + num;
}

string l2str(ll num)
{
    string s = "";
    while(num)
    {
        s = (char)(num % 10 + '0') + s;
        num /= 10;
    }
    return s == "" ? "0" : s;
}

int main()
{
    freopen("input.in", "r", stdin);

    ll n;
    string num;
    cin >> n;
    num = l2str(n);
    // if (dup(num) == 0)
    // {
    //     cout << n << endl;
    //     return 0;
    // }

    add(num, num.length() - 1);

    int now = dup(num);
    while (now)
    {   
        add(num, now);
        now = dup(num);
    }
    cout << num << endl;
    return 0;
}