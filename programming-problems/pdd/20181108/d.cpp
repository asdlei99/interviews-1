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

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    int now = 0;
    for (int i = 0; i < m; i++)
        now += h[i];
    int res = h[m - 1] * m - now;
    for (int i = m; i < n; i++) {
        now -= h[i - m];
        now += h[i];
        res = min(res, h[i] * m - now);
    }
    cout << res << endl;

    return 0;
}
