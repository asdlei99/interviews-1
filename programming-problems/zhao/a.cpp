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
    
    vector<int> c;
    vector<int> s;
    int tmp;  

    cin >> tmp;
    c.push_back(tmp);
    while (cin.get() != '\n') { 
        cin >> tmp; 
        c.push_back(tmp);
    }   
    cin >> tmp;
    s.push_back(tmp);
    while (cin.get() != '\n') { 
        cin >> tmp; 
        s.push_back(tmp);
    }

    sort(c.begin(), c.end());
    sort(s.begin(), s.end());

    int res = 0;
    for (int i = 0; i < c.size(); i++)
    {
        auto it = lower_bound(s.begin(), s.end(), c[i]);
        if (it != s.end())
        {
            s.erase(it);
            res++;
        }    
    }
    cout << res << endl;


    return 0;
}