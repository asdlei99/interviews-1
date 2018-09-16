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

int good[10] = {0,1,5,-1,-1,2,9,-1,8,6};

int toGood(int n)
{
    string res = "";
    while(n > 0)
    {
        int cur = n % 10;
        if (good[cur] == -1) 
            return -1;    
        res = string(1, '0' + good[cur]) + res;
        n /= 10;  
    }
    return stoi(res);
}

int main()
{
    freopen("input.in", "r", stdin);

    int n;
    cin >> n;

    int res = 0;
    
    for (int i = 1; i <= n; i++)
    {
        auto now = toGood(i);
        if (now != -1 && now != i) 
            res++;
    }

    cout << res << endl;

    return 0;
}