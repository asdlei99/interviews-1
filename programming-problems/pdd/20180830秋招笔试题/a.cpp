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

int HP, n, b;

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    scanf("%d %d %d", &HP, &n, &b);
    if (2 * n >= b)
    {
        int res = HP / n + (HP % n ? 1 : 0);
        cout << res << endl;
    }
    else 
    {
        int res;
        int more = HP % b;
        if (more == 0)
        {
            res = HP / b * 2;
        }
        else if (more <= n)
        {
            res = HP / b * 2 + 1; 
        }
        else if (more > n)
        {
            res = HP / b * 2 + 2;
        }
        cout << res << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}