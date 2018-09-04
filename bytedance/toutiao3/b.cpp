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

typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

int mat[55][55];
bool visit[55][55][55][55];
int n, m;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct state
{
    int bx, by;
    int mx, my;
    int times;

    state() : bx(-1), by(-1), mx(-1), my(-1), times(0) {}
    state(int _bx, int _by, int _mx, int _my, int _times) : bx(_bx), by(_by), mx(_mx), my(_my), times(_times) {}

    bool checkman()
    {
        return mx >= 0 && mx < n && my >= 0 && my < m && mat[mx][my] != '#';
    }

    bool checkbox()
    {
        return bx >= 0 && bx < n && by >= 0 && by < m && mat[bx][by] != '#';
    }

    bool checkvisit()
    {
        if (visit[bx][by][mx][my])
            return true;
        visit[bx][by][mx][my] = true;
        return false;
    }
};

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    cin >> n >> m;
    state init;
    int endx, endy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &mat[i][j]);
            if (mat[i][j] == 'S')
            {
                init.mx = i;
                init.my = j;
            }
            else if (mat[i][j] == '0')
            {
                init.bx = i;
                init.by = j;
                // mat[i][j] = '#';
            }
            else if (mat[i][j] == 'E')
            {
                endx = i;
                endy = j;
            }
        }
    }

    init.checkvisit();
    queue<state> q;
    q.push(init);
    int res = -1;

    while (res == -1 && !q.empty())
    {
        auto t = q.front();
        q.pop();

        state ns;
        ns.times = t.times + 1;
        for (int i = 0; i < 4; i++)
        {
            ns.mx = t.mx + dir[i][0];
            ns.my = t.my + dir[i][1];

            if (!ns.checkman())
                continue;
            ns.bx = t.bx;
            ns.by = t.by;
            if (ns.mx == t.bx && ns.my == t.by)
            {
                ns.bx = ns.bx + dir[i][0];
                ns.by = ns.by + dir[i][1];
            }
            if (!ns.checkbox())
                continue;

            if (ns.checkvisit())
                continue;

            if (ns.bx == endx && ns.by == endy) 
            {
                res = ns.times;
                break;
            }
            q.push(ns);
        }
    }

    cout << res << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}