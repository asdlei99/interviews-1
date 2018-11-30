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

#define FF0(i,n) for(int i = 0 ; i < n ; i ++)
#define FF1(i,n) for(int i = 1 ; i <= n ; i ++)

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int M, N;
char mat[105][105];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int visit[105][105][1025];

struct node {
    int key;
    int x, y;
    int step;
    node(int _key, int _x, int _y, int _step): key(_key), x(_x), y(_y), step(_step) {}
};

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> M >> N;
    queue<node> q;
    for (int i = 0; i < M; i++)
    {
        getchar();
        for (int j = 0; j < N; j++)
        {
            scanf("%c", &mat[i][j]);
            if (mat[i][j] == '2')
            {
                q.push(node(0, i, j, 0));
                visit[i][j][0] = 1;
            }        
        }
    }

    bool flag = false;
    int res = 0;
    while(!q.empty())
    {
        node t = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextx = t.x + dir[i][0];
            int nexty = t.y + dir[i][1];
            int nextkey = t.key;

            if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N) continue;
            else if (mat[nextx][nexty] == '3') 
            {
                flag = true;
                res = t.step + 1;
                break;
            }
            else if (mat[nextx][nexty] == '0') continue;
            else if (mat[nextx][nexty] >= 'a' && mat[nextx][nexty] <= 'z')
            {   
                nextkey = t.key | (1 << (mat[nextx][nexty] - 'a'));
            }
            else if (mat[nextx][nexty] >= 'A' && mat[nextx][nexty] <= 'Z')
            {
                if (!(t.key & (1 << ((mat[nextx][nexty] | 32) - 'a')))) 
                    continue;
            }
            // if (visit[nextx][nexty] == -1 || visit[nextx][nexty] != nextkey)
            if (visit[nextx][nexty][nextkey] == 0)
            {
                visit[nextx][nexty][nextkey] = 1;
                q.push(node(nextkey, nextx, nexty, t.step + 1));
            }
                
        }
        if (flag) 
            break;
    }

    cout << res << endl;
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}