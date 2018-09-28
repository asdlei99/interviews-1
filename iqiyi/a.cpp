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

    int n;
    cin >> n;
    vector<int> mat(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mat[i]);
    }
    sort(mat.begin(), mat.end(), greater<int>());
    // for (auto m: mat)
    //     cout << m << " ";
    // cout << endl;


    int res = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        int now = mat[i];
        while(true)
        {
            auto next = upper_bound(mat.begin(), mat.end(), now, greater<int>());
            // for (auto m: mat)
            //     cout << m << " ";
            // cout << endl;
            if (next == mat.end()) break;
            now = *next;
            mat.erase(next);
        }
        res++;
    }
    cout << res << endl;
    
    

    return 0;
}