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

struct tt{
    int val;
    int index;
    tt(int _val, int _index): val(_val), index(_index) {}
    bool operator<(const tt& t) const {
        return val < t.val;
    }
};

int count(int index, vector<ll>& s)
{
    if (index == 0) return s[0] + s[1];
    if (index == s.size() - 1) return s[index] + s[index - 1];
    return min(s[index - 1], s[index + 1]) + s[index];
}

int find(vector<ll>& s)
{
    int mn = 0;
    int mnn = s[0] + s[1]; 
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] < s[mn] || (s[i] == s[mn] && count(i, s) < count(mn, s)))
        {
            mn = i;
        }
    }
    return mn;
}

int main()
{
    freopen("input.in", "r", stdin);

    int n, m;

    cin >> n >> m;

    vector<ll> s(n);
    vector<tt> ss;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < m; i++)
    {
        int mn = find(s);
        int adj = 0;
        if (mn == 0) 
        {
            adj = 1;
        }
        else if (mn == n - 1)
        {
            adj = n - 2;
        }
        else 
        {
            adj = s[mn - 1] < s[mn + 1] ? mn - 1 : mn + 1;
        }

        s[mn] = s[mn] + s[adj];
        s.erase(s.begin() + adj);

        n--;
    }

    cout << s[find(s)] << endl;

    return 0;
}