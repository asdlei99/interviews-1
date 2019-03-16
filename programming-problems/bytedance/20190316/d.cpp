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
const double eps = 1e-4;

int n, m;
// const int MAXN = 1e9;
// double l[MAXN];

bool ok(double res, vector<double> &l) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += l[i] / res;
    }
    return num >= m;
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);


    cin >> n >> m;
    vector<double> l(n);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        sum += l[i];
    }

    double right = sum / m;
    double left = 0.0;
    double res = (right + left) / 2;

    while (right - left > eps) {
        printf("%.2f\n", res);
        res = (right + left) / 2;
        if (ok(res, l)) {
            left = res;
        } else {
            right = res;
        }
    }
    printf("%.2f\n", res);

    return 0;
}
