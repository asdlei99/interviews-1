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

    int N;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int start = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i > 1 && a[i - 2] > a[i - 1] && a[i] > a[i - 1]) start = i - 1;
        }

        vector<ll> s(n, 1);
        for (int i = 0; i < n; i++) {
            int now = (start + i) % n;
            int next = (now + 1) % n;
            if (a[next] > a[now]) s[next] = s[now] + 1;
        }

        for (int i = 0; i < n; i++) {
            int now = (start + n - i) % n;
            int next = (now + n - 1) % n;
            if (a[next] > a[now] && s[next] <= s[now]) s[next] = s[now] + 1;
        }

        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += s[i];
        }
        cout << res << endl;
    }


    return 0;
}
