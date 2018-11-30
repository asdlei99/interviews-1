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
const int MOD = 1e9 + 7;

int T;
int N, M;

/**
 *  Not Completed.
 *  2018/09/10
 *  pwxcoo
 * 
 */

int main()
{
    freopen("input.in", "r", stdin);

    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        vector<vector<ll>> f(N + 1, vector<ll>(M + 1, 0));

        for (int i = 0; i <= M; i++) f[0][i] = 1;
        for (int i = 0; i <= N; i++) f[i][0] = 1;

        for (int n = 1; n <= N; n++)
        {
            for (int m = 1; m <= M; m++)
            {
                for (int up = 0; up <= n - 1 ; up++)
                {
                    for (int size = 1; size <= 4; size++)
                    {
                        ll tmp = 0;
                        for (int left = 0; left <= (m - size)/2 && left >= 0    ; left++)
                        {
                            tmp += f[1][left] * f[1][m - size - left] * f[up][m] * f[n - up - 1][m]  % MOD;
                            tmp %= MOD;
                        }
                        f[n][m] = (f[n][m] + tmp) % MOD;
                    }
                }
            }
        }

        
        cout << f[N][M] << endl;
    }

    return 0;
}