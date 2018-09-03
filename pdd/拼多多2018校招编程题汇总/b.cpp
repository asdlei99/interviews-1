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

#define FF0(i,n) for(int i = 0 ; i < n ; i ++)
#define FF1(i,n) for(int i = 1 ; i <= n ; i ++)

typedef long long ll;
const int INF = 0x7fffffff;

int m, n;
int u, v, d;
int path[105][105];

set<int> count(int now, vector<vector<int>> &t)
{
    set<int> res;
    res.insert(0);
    if (t[now].size() == 0)
    {
        
        return res;
    }

    int len = t[now].size();
    vector<set<int>> cnts(len);
    for (int i = 0; i < len; i++)
    {
        cnts[i] = count(t[now][i], t);
    }
    
    for (int i = 0; i < len; i++)
    {
        for (auto c: cnts[i]) res.insert(c + path[now][t[now][i]]);
        for (int j = i + 1; j < len; j++)
        {
            for (auto a: cnts[i])
                for (auto b: cnts[j])
                    res.insert(a + b + path[now][t[now][i]] + path[now][t[now][j]]);
        }
    }

    return res;
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    while(scanf("%d %d", &m, &n) != EOF)
    {
        vector<vector<int>> t(n);
        int root = 0;
        vector<int> rr(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &u, &v, &d);
            t[u].push_back(v);
            path[u][v] = d;
            rr[v] = 1;
        }

        for (int i = 0; i < n; i++)
            if (rr[i] == 0)
            {
                root = i;
                break;
            }

        int ans = 0;
        auto res = count(root, t);
        for (auto it = res.rbegin(); it != res.rend(); it++)
        {
            if (*it <= m)
            {
                ans = *it;
                break;
            }
        }
        printf("%d\n", ans);
    }
    
    
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}