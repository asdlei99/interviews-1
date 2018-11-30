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

int m, n, k;

int main()
{
    freopen("input.in", "r", stdin);

    cin >> m >> n >> k;

    int t1, t2;
    vector<int> de(m + 1, 0);
    vector<vector<int>> to(m + 1, vector<int>(0)); 
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &t1, &t2);
        de[t1]++;
        to[t2].push_back(t1);
    }

    queue<int> q;
    int day = 0, res = 0;;

    vector<int> visit(m + 1, 0);
    while(true)
    {
        vector<int> today;
        day++;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 1; j <= m; j++)
            {
                if (de[j] == 0 && visit[j] == 0)
                {
                    visit[j] = 1;
                    flag = true;
                    today.push_back(j);
                    res++;
                    break;
                }
            }
            if (!flag) break;
        }

        if (today.size() == 0) break;
        for (int i = 0; i < today.size(); i++)
        {
            for (int next: to[today[i]])
            {
                de[next]--;
            }
        }
    }


    if (res == m)
        cout << day - 1 << endl;
    else
        cout << "E" << endl;

    return 0;
}