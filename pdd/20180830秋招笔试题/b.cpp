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

int n, m;
char mat[12][12];

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < m; j++)
        {
            
            scanf("%c", &mat[i][j]);
        }
    }
    
    for (int j = 0; j < m; j++)
    {
        int block = n + 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mat[i][j] == 'x')
            {
                block = i;
            }
            else if (mat[i][j] == 'o')
            {
                if (block >= n)
                    mat[i][j] = '.';
                else
                {
                    mat[i][j] = '.';
                    mat[--block][j] = 'o';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}