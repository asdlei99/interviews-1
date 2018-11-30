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
const int mod = 1000000007;

int n;
ll dp[1005];
int m[1005];

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }

    dp[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod - dp[m[i] - 1] + 2;
        dp[i] %= mod;
    }

    cout << dp[n] + 1 << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}