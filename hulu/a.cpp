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

int n;

int main()
{
    freopen("input.in", "r", stdin);

    cin >> n;
    vector<int> a(n);
    vector<int> cnt(100001, 0);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    // sort(a.begin(), a.end());

    vector<int> sum(mx + 1, 0);
    for (int i = 1; i <= mx; i++)
    {
        // sum[i] = sum[i - 1];
        sum[i] = sum[i - 1] + cnt[i - 1] * (i - 1);
    }

    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
        res[i] = sum[a[i]];

    for (int i = 0; i < n; i++)
        cout << res[i] << endl;

    return 0;
}