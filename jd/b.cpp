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

struct goods {
    int a, b, c;
    goods(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    bool operator<(const goods& g)const {
        if (a != g.a)
            return a <= g.a;
        else if (b != g.b)
            return b <= g.b;
        else
            return c <= g.c;
    }
};

int main()
{
    freopen("input.in", "r", stdin);

    int n;
    cin >> n;
    vector<goods> g;
    int _a, _b, _c;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &_a, &_b, &_c);
        g.push_back(goods(_a, _b, _c));
    }
    sort(g.begin(), g.end());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (g[j].a > g[i].a && g[j].b > g[i].b && g[j].c > g[i].c)
            {
                res++;
                break;
            }
        }
    }
    cout << res << endl;

    return 0;
}