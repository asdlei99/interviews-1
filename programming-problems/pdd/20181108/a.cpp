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

    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        cnt[s[i] - 'a']++;
    }

    sort(cnt.begin(), cnt.end());
    cnt[25] += cnt[24];
    cnt[24] = 0;
    ll res = 0;
    for (int i = 0; i < 26; i++) {
        res += cnt[i] * cnt[i];
    }
    cout << res << endl;

    return 0;
}
