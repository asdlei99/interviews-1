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

int T;

int main()
{
    freopen("input.in", "r", stdin);

    cin >> T;
    ll X, A, C, Y, B, D;

    while(T--)
    {
        cin >> X >> A >> C >> Y >> B >> D;

        ll zhi = Y / A * C;
        ll chun = X / B * D;

        if (zhi == chun)
        {
            bool needzhi = Y % A != 0;
            bool needchun = X % B != 0;
            if (needzhi && needchun)
                cout << "TIE" << endl;
            else if (needzhi && !needchun)
                cout << "XIAOCHUN" << endl;
            else if (!needzhi && needchun)
                cout << "XIAOZHI" << endl;
            else
            {
                if (C == D)
                    cout << "TIE" << endl;
                else if (C < D)
                    cout << "XIAOCHUN" << endl;
                else 
                    cout << "XIAOZHI" << endl;
            }
        }
            
        else if (zhi < chun)
            cout << "XIAOZHI" << endl;
        else if (zhi > chun)
            cout << "XIAOCHUN" << endl;

    }


    return 0;
}