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

struct point{
    double x, y;
    point(double _x, double _y): x(_x), y(_y) {}
};

double dis(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool isTriangle(point a, point b, point c)
{
    double ab = dis(a, b);
    double ac = dis(a, c);
    double bc = dis(b, c);
    return  ab + ac - bc > eps && ab + bc - ac > eps && bc + ac - ab > eps;
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    int n;
    while(scanf("%d", &n) != EOF)
    {
        vector<point> p;
        double x, y;
        FF0(i, n)
        {
            scanf("%lf %lf", &x, &y);
            p.push_back(point(x, y));
        }

        int res = 0;
        FF0(i, n)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    res += isTriangle(p[i], p[j], p[k]) ? 1 : 0;
                }
            }
        }

        printf("%d\n", res);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}