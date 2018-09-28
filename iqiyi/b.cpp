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

    int n;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;

    

    return 0;
}