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

int t;
ll n, k, d1, d2;

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> d1 >> d2;

        ll surplus = n - k;
        ll one = surplus - (d1 + d2);  /* -d1 0 -d2 */
        ll two = surplus - (abs(d1 - d2) + max(d1, d2)); /* d1 0 d2 */
        ll three = surplus - (d2 + 2 * d1); /* d1 0 -d2 */
        ll four = surplus - (d1 + 2 * d2);  /* -d1 0 d2 */
        
        if (one >= 0 && one % 3 == 0 && (k + d1 + d2) % 3 == 0 && (k + d1 + d2) / 3 >= max(d1, d2)|| 
            two >= 0 && two % 3 == 0 && (k - d1 - d2) >= 0 && (k - d1 - d2) % 3 == 0 || 
            three >= 0 && three % 3 == 0 && (k + d2 - d1) % 3 == 0 && (k + d2 - d1) / 3 >= d2 || 
            four >= 0 && four % 3 == 0 && (k + d1 - d2) % 3 == 0 && (k + d1 - d2) / 3 >= d1)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}