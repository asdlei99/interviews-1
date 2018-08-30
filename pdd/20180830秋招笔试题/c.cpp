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

ll a, b;

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> a >> b;

    a = a % b;

    unordered_map<ll, int> visit;
    int start = 0, len = 0, now = 0;;
    while(true)
    {
        if (a == 0)
        {
            start = now;
            break;
        }
        a *= 10;

        if (visit.find(a) != visit.end())
        {
            start = visit[a];
            len = now - start; 
            break;
        }
        else
        {
            visit[a] = now;
        }

        a %= b;
        now++;
    }

    printf("%d %d\n", start, len);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}