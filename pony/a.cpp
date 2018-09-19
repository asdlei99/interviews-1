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

int n;
bool flag;
vector<ll> res;

bool check(vector<ll> A)
{
    if (n == 1) return true;

    int diff = A[1] - A[0];
    for (int i = 1; i < n; i++)
        if (A[i] - A[i - 1] != diff)
            return false;
    return true;
}

void dfs(vector<ll>& A, int now, int diff)
{
    if (now >= n) 
    {
        flag = true;
        for (auto a: A)
            res.push_back(a);
        return;
    }
    if (flag) return;

    ll origin = A[now];
    for (int i = 1; A[now] - A[now - 1] <= diff; )
    {
        A[now] = origin * i;
        if (A[now] - A[now - 1] == diff)
        {
            dfs(A, now + 1, diff);
            break;
        }

        i *= 2;
    }
    A[now] = origin;
}

int main()
{
    freopen("input.in", "r", stdin);

    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) scanf("%lld", &A[i]);

    flag = false;
    ll originH = A[0];
    ll origin = A[1];
    for (int i = 1; i < 65537 && !flag; )
    {
        A[0] = originH * i;
        for (int j = 1; j < 65537 && !flag; )
        {
            A[1] = origin * j;
            dfs(A, 1, A[1] - A[0]);

            j *= 2;
        }
        i *= 2;
    }

    for (auto r: res)
        cout << r << endl;

    return 0;
}