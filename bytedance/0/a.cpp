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

int n, q, l, r, k;

struct person {
    int id;
    int like;
    person(): id(-1), like(-1) {}
    person(int _id, int _like): id(_id), like(_like) {}
    bool operator<(const person& p)const {
        return like < p.like;
    }
};

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    
    scanf("%d", &n);
    vector<person> users(n + 1);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &users[i].like);
        users[i].id = i;
    }

    sort(users.begin(), users.end());

    scanf("%d", &q);

    while(q--)
    {
        cin >> l >> r >> k;
        int left = lower_bound(users.begin(), users.end(), person(0, k)) - users.begin();
        int right = upper_bound(users.begin(), users.end(), person(0, k)) - users.begin();

        int res = 0;
        for (int i = left; i < right; i++)
        {
            if (users[i].id >= l && users[i].id <= r) res++;
        }
        cout << res << endl;
    }
    


    fclose(stdin);
    fclose(stdout);
    return 0;
}