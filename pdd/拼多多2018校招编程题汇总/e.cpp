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
const double eps = 1e-8;

int n, m;

struct bear{
    int id, fight, hungry;
    bear(): fight(0), hungry(0) {}
    bear(int _fight, int _hungry): fight(_fight), hungry(_hungry) {}
    bool operator<(const bear& a)const 
    {
        return fight > a.fight;
    }
};

bool cmp(const bear& a, const bear& b) 
{
    return a.id < b.id;
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    while(scanf("%d %d", &n, &m) != EOF)
    {
        vector<bear> bs(n);
        vector<int> sugar(m);
        for (int i = 0; i < m; i++) scanf("%d", &sugar[i]);
        for (int i = 0; i < n; i++) scanf("%d %d", &bs[i].fight, &bs[i].hungry);
        for (int i = 0; i < n; i++) bs[i].id = i;

        sort(bs.begin(), bs.end());
        sort(sugar.begin(), sugar.end(), greater<int>());

        for (int i = 0; i < n; i++)
        {
            while (bs[i].hungry)
            {
                auto s = lower_bound(sugar.begin(), sugar.end(), bs[i].hungry, greater<int>());
                if (s == sugar.end())
                    break;
                bs[i].hungry -= *s;
                sugar.erase(s);
            }
        }

        sort(bs.begin(), bs.end(), cmp);
        for (int i = 0; i < n; i++) printf("%d\n", bs[i].hungry);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}