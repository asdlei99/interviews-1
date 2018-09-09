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

int T;
int n, m;



int main()
{
    freopen("input.in", "r", stdin);
    
    cin >> T;
    
    while(T--)
    {
        cin >> n >> m;
        vector<unordered_set<int>> mat(n + 1);
        int x, y;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            mat[x].insert(y);
            mat[y].insert(x);
        }

        vector<int> visit(n + 1, 0);
        bool flag = true;
        for (int i = 1; i <= n && flag; i++)
        {
            // if (visit[i] == 0)
            // {
                unordered_set<int> in;
                in.insert(i);
                for (int j = i + 1; j <= n; j++)
                {
                    if (mat[i].find(j) == mat[i].end())
                    {
                        for (int inn: in)
                        {
                            if (mat[j].find(inn) != mat[j].end())
                            {
                                flag = false;
                            }
                        }

                        for (int out: mat[i])
                        {
                            if (mat[j].find(out) == mat[j].end())
                            {
                                flag = false;
                            }
                        }
                        if (flag) in.insert(j);
                        else break;
                    }

                }
            // }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}