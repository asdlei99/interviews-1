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

int main()
{
    freopen("input.in", "r", stdin);

    ll k, b, n, t;
    cin >> k >> b >> n >> t;

    ll sum = 1;
    vector<int> kk(n + 1);
    kk[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum = k * sum + b;
        kk[i] = k * kk[i - 1];
    }

    cout << sum << endl;

    ll now = 1;
    int i = 1;
    for (; i <= n; i++)
    {
        now = k * now + b;
        
    }


    cout << i << endl;


    return 0;
}