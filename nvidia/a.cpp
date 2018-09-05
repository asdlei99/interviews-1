#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int minSwapTime(vector < int > values) {
    values.insert(values.begin(), 0);
    int n = values.size() - 1;
    vector<int> res;
    stack<int> q;

    int now = 1;
    while(!q.empty() || now <= n)
    {
        while(now <= n) 
        {
            q.push(now);
            now = 2 * now;
        }

        if (!q.empty())
        {
            now = q.top(); q.pop();
            res.push_back(values[now]);
            now = 2 * now + 1;
        }
    }

    vector<int> temp(res);
    sort(temp.begin(), temp.end());
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[temp[i]] = i;
    }

    int loops = 0;
    vector<bool> flag(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!flag[i])
        {
            int j = i;
            while (!flag[j])
            {
                flag[j] = true;
                j = m[res[j]];
            }
            loops++;
        }
    }
    return n - loops;
}
/******************************结束写代码******************************/


int main() {
    int res;
    freopen("input.in", "r", stdin);
    int _values_size = 0;
    cin >> _values_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _values;
    int _values_item;
    for(int _values_i=0; _values_i<_values_size; _values_i++) {
        cin >> _values_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _values.push_back(_values_item);
    }


    
    res = minSwapTime(_values);
    cout << res << endl;
    
    return 0;

}
