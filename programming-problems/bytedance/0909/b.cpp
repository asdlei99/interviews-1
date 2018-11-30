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

int m;
int mat[1005][1005];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int main()
{
    freopen("input.in", "r", stdin);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }


    vector<vector<int>> visit(m, vector<int>(m, 0));
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && !visit[i][j])
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j] = 1;
                while(!q.empty())
                {
                    auto t = q.front(); q.pop();

                    for (int d = 0; d < 4; d++)
                    {
                        int nx = t.first + dir[d][0];
                        int ny = t.second + dir[d][1];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= m || 
                            mat[nx][ny] != 1 || visit[nx][ny] == 1)
                            continue;
                        visit[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
                res++;
            }
        }
    }  
    cout << res << endl;

    return 0;
}