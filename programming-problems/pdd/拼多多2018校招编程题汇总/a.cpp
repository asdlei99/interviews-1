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

int offset, n, l1, l2;

int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("", "w", stdout);

    int start1, end1, start2,  end2;
    while (scanf("%d %d %d %d", &offset, &n, &l1, &l2) != EOF)
    {
        int sum = l1 + l2;
        int end = offset + n;

        if (end <= l1)  /* belong to l1 */
        {
            printf("%d %d %d %d\n", offset, end, 0, 0);
        }
        else if (offset < l1 && end > l1) /* belong to l1&l2 */
        {
            printf("%d %d %d %d\n", offset, l1, 0, end < sum ? (end - l1) : l2);
        }
        else if (offset >= l1)  /* belong to l2 */
        {
            printf("%d %d %d %d\n", l1, l1, (offset - l1) < l2 ? (offset - l1) :l2, end < sum ? (end - l1) : l2);
        }
    }
    
    // fclose(stdin);
    // fclose(stdout);


    return 0;
}