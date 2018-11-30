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
const int N = 1e4 +5;

int visit[N];
int n;

bool bfs(vector<vector<int>>& mat, int x)
{
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(x);
    visit[x] = 1;

    int count = 0;
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        count++;
        for (auto nx: mat[t])
        {
            if (visit[nx] != 1)
            {
                visit[nx] = 1;
                q.push(nx);
            }
        }
    }
    return count == n;
}

int main()
{
    freopen("input.in", "r", stdin);

    int m;
    cin >> n >> m;
    int from, to;
    vector<vector<int>> mat(n + 1, vector<int>(0));
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &from, &to);
        mat[to].push_back(from);
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += bfs(mat, i) ? 1 : 0;
    }
    cout << res << endl;

    return 0;
}