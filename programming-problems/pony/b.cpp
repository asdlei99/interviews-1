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

/**
 *  2018/09/19
 *  Not Completed
 */


typedef long long ll;
const int INF = 0x7fffffff;
const double eps = 1e-8;

char mat[16][16];

int check(int x, int y, char c, int count)
{
    bool flag = false;
    int i, res;
    
    i = 0; res = 0;
    while(true)
    {
        if (x + i < 15 && mat[x + i][y] == c)
        {
            res++;
            i++;
        }
        else
        {
            if (res >= count && res <= 9) return 1;
            else if (res > 9) return -1;
            break;
        }
    }

    i = 0; res = 0;
    while(true)
    {
        if (y + i < 15 && mat[x][y + i] == c)
        {
            res++;
            i++;
        }
        else
        {
            if (res >= count && res <= 9) return 1;
            else if (res > 9) return -1;
            break;
        }
    }

    i = 0; res = 0;
    while(true)
    {
        if (x + i < 15 && y + i < 15 && mat[x + i][y + i] == c)
        {
            res++;
            i++;
        }
        else
        {
            if (res >= count && res <= 9) return 1;
            else if (res > 9) return -1;
            break;
        }
    }

    return 0;
}

int main()
{
    freopen("input.in", "r", stdin);

    int b = 0, w = 0;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
        {
            scanf("%c ", &mat[i][j]);
            if (mat[i][j] == 'B') 
                b++;
            else if (mat[i][j] == 'W')
                w++;
        }


    if (b != w && b != w + 1)
    {
        cout << "invalid board" << endl;
        return 0;
    }

    int res[2] = {0, 0};
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
        {
            if (mat[i][j] == 'B')
            {
                int r = check(i, j, 'B', 5);
                if (r == 1)
                {
                    res[0] = 1;
                    // cout << "black win" << endl;
                    // return 0;
                }        
                else if (r == -1)
                {
                    cout << "invalid board" << endl;
                    return 0;
                }
            }
            else if (mat[i][j] == 'W')
            {
                int r = check(i, j, 'W', 5);
                if (r == 1)
                {
                    res[1] = 1;
                    // cout << "white win" << endl;
                    // return 0;
                }        
                else if (r == -1)
                {
                    cout << "invalid board" << endl;
                    return 0;
                }

            }
        }
    
    if (res[0] && res[1])
        cout << "invalid board" << endl;
    else if (res[0])
        cout << "black win" << endl;
    else if (res[1])
        cout << "white win" << endl;
    else
    {
        if (b + w == 255)
            cout << "draw" << endl;
        else
            cout << "not finished" << endl;

    }
        

    return 0;
}