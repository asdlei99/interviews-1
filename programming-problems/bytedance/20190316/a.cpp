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
    n = 1024 - n;

    int res = 0;
    res += n / 64;
    n %= 64;

    res += n /16;
    n %= 16;

    res += n / 4;
    n %= 4;

    res += n;

    cout << res << endl;


    return 0;
}
