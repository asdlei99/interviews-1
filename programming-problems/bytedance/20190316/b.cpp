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

    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;

        int len = s.length();
        string res = "";
        for (int i = 0; i < len; i++) {
            if (i + 2 < len && s[i] == s[i + 1] && s[i] == s[i + 2]) {
                continue;
            }

            res += s[i];
        }

        string res1 = "";
        int l = res.length();
        for (int i = 0; i < l; i++) {
            if (i + 3 < l && res[i] == res[i + 1] && res[i + 2] == res[i + 3]) {
                res1 += res.substr(i, 2);
                i = i + 2;
                continue;
            }

            res1 += res[i];
        }

        cout << res1 << endl;
    }


    return 0;
}
