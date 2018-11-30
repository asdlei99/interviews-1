#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int n, l;
string res;
unordered_set<string> m;

void dfs(vector<set<char>> &rec, string now)
{
    if (res != "-")
        return;
    int cur = now.length();
    if (cur == l)
    {
        if (m.find(now) == m.end())
        {
            if (res == "-")
            {
                res = now;
                return;
            }
        }
    }

    for (int i = cur; i < l; i++)
    {
        for (auto rr : rec[cur])
        {
            string next = now + rr;
            dfs(rec, next);
        }
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    cin >> n >> l;
    string s;

    vector<set<char>> rec(l);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        m.insert(s);
        for (int j = 0; j < l; j++)
        {
            rec[j].insert(s[j]);
        }
    }

    res = "-";
    dfs(rec, "");
    cout << res << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}