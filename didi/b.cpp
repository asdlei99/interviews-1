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


int main()
{
    freopen("input.in", "r", stdin);

    vector<int> c(4);
    for (int i = 0; i < 4; i++)
        scanf("%d", &c[i]);
    
    vector<int> o(4);
    for (int i = 0; i < 4; i++)
        o[i] = i + 1;
    
    int now = 0;
    stack<int> st;
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        if (st.empty() || c[i] > now)
        {
            while(now != c[i])
            {
                st.push(++now);
            }
        }
        
        if (st.top() == c[i])
        {
            st.pop();
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
        

    

    return 0;
}