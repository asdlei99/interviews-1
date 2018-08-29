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


int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    int n, m;
    scanf("%d", &n);
    vector<int> child(n);
    for (int i = 0; i < n; i++) scanf("%d", &child[i]);
    scanf("%d", &m);
    vector<int> chocolate(m);
    for (int i = 0; i < m; i++) scanf("%d", &chocolate[i]);

    sort(child.begin(), child.end());
    sort(chocolate.begin(), chocolate.end());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(chocolate.begin(), chocolate.end(), child[i]);
        if (it == chocolate.end()) break;
        res++;
        chocolate.erase(it);
    }

    printf("%d\n", res);

    fclose(stdin);
    fclose(stdout);
    return 0;
}