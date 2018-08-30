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

string str;
int m;
vector<int> arr[26];


int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    cin >> str >> m;
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 'a'].push_back(i);
    }

    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        int len = arr[i].size();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int j = len - 1; j >= 0; j--)
        {
            for (int k = j; k < len; k++)
            {
                if (j == k)
                {
                    dp[j][k] = 0;
                }
                else if (j + 1 == k)
                {
                    dp[j][k] = arr[i][k] - arr[i][j] - 1;
                }
                else
                {
                    dp[j][k] = dp[j + 1][k - 1] + arr[i][k] - arr[i][j] - (k - j);
                    if (dp[j][k] <= m)
                        res = max(res, k - j + 1);    
                }
            }
        }
    }
    
    cout << res << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}