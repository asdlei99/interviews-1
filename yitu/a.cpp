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

    string s;
    cin >> s;

    stack<char> st;
    int len = s.length();
    int res = 0;
    for (int i = 0; i < len && !res; i++)
    {
        if(s[i] == '(')
        {
            st.push('(');
        }
        else if(s[i] == '[')
        {
            st.push('[');
        }
        else if(s[i] == '{')
        {
            st.push('{');
        }
        else if(s[i] == ']')
        {
            if(st.empty() || st.top() != '[')
                res = 1;
            else
                st.pop();
        }
        else if(s[i] == ')')
        {
            if(st.empty() || st.top() != '(')
                res = 1;
            else
                st.pop();
        }
        else if(s[i] == '}')
        {
            if(st.empty() || st.top() != '{')
                res = 1;
            else
                st.pop();
        }
    }

    if (!st.empty()) res = 1;
    if (s[0] != '"' || s[len - 1] != '"') res = 1;
    cout << res << endl;
    return 0;
}