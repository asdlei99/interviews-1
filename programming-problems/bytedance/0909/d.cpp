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

int res;

bool valid(vector<int>& num)
{
    // for (auto nu: num)
    //     cout << nu << " ";
    // cout << endl;

    int n = num.size();

    for (int i = 0; i < n; i++)
    {
        num[i] = num[i] & 255;
    }

    if (n == 1)
    {
      return num[0] >= 0 && num[0] <= 127;
    } 
    else if (n == 2)
    {
        return num[0] >= 192 && num[0] <= 223 &&
               num[1] >= 128 && num[1] <= 191;  
    } 
    else if (n == 3)
    {
        return num[0] >= 224 && num[0] <= 239 &&
                num[1] >= 128 && num[1] <= 191 &&
                num[2] >= 128 && num[2] <= 191; 
    }
    else if (n == 4) 
    {
        return num[0] >= 240 && num[0] <= 247 &&
                num[1] >= 128 && num[1] <= 191 &&
                num[2] >= 128 && num[2] <= 191 &&
                num[3] >= 128 && num[3] <= 191; 
    } 
    return false;  
}

void dfs(vector<int>& num, vector<int> cur, int now)
{
    if (res == 1 || cur.size() > 4 || now > num.size()) return;
    if (valid(cur))
    {
        res = 1;
        return;
    }

    for (int i = now; i < num.size(); i++)
    {
        cur.push_back(num[i]);
        dfs(num, cur, i + 1);
        cur.pop_back();
    }
}

int main()
{
    freopen("input.in", "r", stdin);

    int n;
    cin >> n;
    vector<int> uni(n);
    for (int i = 0; i < n; i++) cin >> uni[i];
    sort(uni.begin(), uni.end(), greater<int>());
    res = 0;
    // vector<int> cur;
    // dfs(uni, cur, 0);
    res = valid(uni) ? 1 : 0;
    cout << res << endl;


    return 0;
}