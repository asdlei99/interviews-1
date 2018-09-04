#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define FF0(i, n) for (int i = 0; i < n; i++)
#define FF1(i, n) for (int i = 1; i <= n; i++)

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int n, m, c;

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    cin >> n >> m >> c;

    vector<vector<int>> chain(n);
    int num_i, x;
    for (int i = 0; i < n; i++)
    {
        cin >> num_i;
        for (int j = 0; j < num_i; j++)
        {
            scanf("%d", &x);
            chain[i].push_back(x);
        }
    }

    vector<int> res(c + 1, 0);
    int ans = 0;
    unordered_map<int, int> window;
    for (int i = 0; i < m; i++)
    {
        if (i >= n)
            break;
        for (auto cc : chain[i])
        {
            window[cc]++;
            if (window[cc] > 1)
            {
                if (res[cc] == 0)
                {
                    res[cc] = 1;
                    ans++;
                }
            }
        }
    }

    if (m < n)
    {
        int left = 0, right = m - 1;
        while (left < n)
        {
            left++;
            right++;
            right %= n;

            for (auto cc : chain[left - 1])
            {
                window[cc]--;
            }
            for (auto cc : chain[right])
            {
                window[cc]++;
                if (window[cc] > 1)
                {
                    if (res[cc] == 0)
                    {
                        res[cc] = 1;
                        ans++;
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}