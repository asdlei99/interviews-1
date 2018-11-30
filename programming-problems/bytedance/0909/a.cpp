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

string str;

int main()
{
    freopen("input.in", "r", stdin);
    
    cin >> str;

    int len = str.length();
    int res = 0;

    unordered_set<int> m;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        while(m.find(str[i]) != m.end())
        {
            m.erase(str[start++]);
        }
        m.insert(str[i]);
        res = max(res, i - start + 1);
    }
    cout << res << endl;

    return 0;
}