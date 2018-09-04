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

int cnt[50005];
int n, m;
string str;

bool ok(int len)
{
    int l = 0, r = l + len;
    for (; r <= n; l++, r++)
    {
        if (len - (cnt[r] - cnt[l]) <= m) return true;
        if (cnt[r] - cnt[l] <= m) return true;
    }
    return false;
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> n >> m;
    cin >> str;

    // cnt[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = str[i - 1] == 'a' ? cnt[i - 1] + 1: cnt[i - 1];
    }

    int left = 0, right = n;
    int res = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (ok(mid))
        {
            res = mid;
            left = mid + 1;
        }
        else 
            right = mid - 1; 

    }

    cout << res << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}