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

int p[4], neg[4];

void add_positive(int num)
{
    p[3] = num;
    int now = 2;
    while (now >= 0 && p[now] < p[now + 1])
    {
        swap(p[now], p[now+1]);
        now--;
    }
}

void add_negative(int num)
{
    neg[2] = num;
    int now = 1;
    while (now >= 0 && neg[now] > neg[now + 1])
    {
        swap(neg[now], neg[now+1]);
        now--;
    }
}

void add_negative_biggest(int num)
{
    neg[3] = num;
    int now = 2;
    while (now >= 0 && neg[now] < neg[now + 1])
    {
        swap(neg[now], neg[now+1]);
        now--;
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if (n < 3) return 1; /* input error */

        vector<ll> A;
        int temp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            if (temp > 0) cnt++;
            A.push_back(temp);
        }

        ll res = A[0] * A[1] * A[2];

        p[0] = p[1] = p[2] = 0;
        neg[0] = neg[1] = 0;
        if (cnt >= 3) 
        /* max(3 biggest positive, 1 biggest positive and 2 smallest negative) */
        {
            FF0(i,n)
            {
                if (A[i] > 0) add_positive(A[i]);
                else if (A[i] < 0) add_negative(A[i]);
                else res = max(0LL, res);
            }
            res = max(res, max((ll)p[0] * p[1]* p[2], (ll)p[0] * neg[0] * neg[1]));
        }
        else if (cnt >= 1)
        /* 1 biggest positive and 2 smallest negative */
        {
            FF0(i,n)
            {
                if (A[i] > 0) add_positive(A[i]);
                else if (A[i] < 0) add_negative(A[i]);
                else res = max(0LL, res);
            }
            res = max(res, (ll)p[0] * neg[0] * neg[1]);
        }
        else if (cnt == 0)
        /* 3 biggest negative */
        {
            FF0(i,n)
            {
                if (A[i] == 0) res = max(0LL, res);
                else add_negative_biggest(A[i]);
            }
            res = max(res, (ll)neg[0] * neg[1] * neg[2]);
        }

        printf("%lld\n", res);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}