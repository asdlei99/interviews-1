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

int n;

int main()
{
    freopen("input.in", "r", stdin);

    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    sort(p.begin(), p.end());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (p[k] - p[j] > 18000 || p[j] - p[i] > 18000 || (36000 - p[k] + p[i]) > 18000)
                {
                    res++;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}