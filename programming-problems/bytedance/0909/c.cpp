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

string ip;
int res;

bool valid(string s)
{
    int value = stoi(s);
    if (s[0] == '0') return (s.size() == 1);
    else 
    {
        if (value <= 255) return true;
        else return false;
    }
}

int main()
{
    freopen("input.in", "r", stdin);

    cin >> ip;
    res = 0;
    
    int len = ip.length();
    if (len > 12 || len < 4) 
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len - 1; k++)
            {
                string ip1 = ip.substr(0, i + 1);
                string ip2 = ip.substr(i + 1, j - i);
                string ip3 = ip.substr(j + 1, k - j);
                string ip4 = ip.substr(k + 1);
                if (valid(ip1) && valid(ip2) && valid(ip3) && valid(ip4))
                {
                    res++;
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}