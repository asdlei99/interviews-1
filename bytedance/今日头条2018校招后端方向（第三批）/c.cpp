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
const int MAXN = 1e5 + 5;

int n, x;
ll a[MAXN];

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int s, len;
    ll sum, mmin = INF;
    for (int i = 0; i < n; i++)
    {
        int now = (x - 1 + n - i) % n;
        if (a[now] < mmin)
        {
            mmin = a[now];
            s = now;
            len = (x - 1 - now + n) % n;
            sum = n * mmin + len; 
        }
    }

    for (int i = 1; i <= len; i++)
        a[(s + i) % n] -= 1;
    for (int i = 0; i < n; i++)
    {
        a[i] -= mmin;
    }
    a[s] = sum;

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}   