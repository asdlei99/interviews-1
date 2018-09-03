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

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    string a, b;
    cin >> a >> b;
    
    int l1 = a.length(), l2 = b.length();
    vector<int> sum(l1 + l2, 0);

    for (int i = l1 - 1; i >= 0; i--)
    {
        for (int j = l2 - 1; j >= 0; j--)
        {
            int temp = (a[i] - '0') * (b[j] - '0') + sum[i + j + 1];
            sum[i + j + 1] = temp % 10;
            sum[i + j] += temp / 10;
        }
    }

    string res = "";
    for (auto num: sum)
    {
        if (!(res.length() == 0 && num == 0))
            res += num + '0';
    }
    
    res == "" ? printf("0\n") : printf("%s\n", res.c_str());

    fclose(stdin);
    fclose(stdout);

    return 0;
}