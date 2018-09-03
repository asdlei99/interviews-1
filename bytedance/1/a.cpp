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

int res = 0;

int rot[6][24] = 
{
    { 1, 3, 0, 2, 23, 22, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, 8 },
    { 10, 4, -1, -1, 18, -1, -1, -1, -1, 0, 19, -1, -1, -1, -1, 1, -1, -1, 15, 9, 21, 23, 20, 22 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 21, 20, 10, 11, 12, 13, 18, 16, 19, 17, 15, 14, -1, -1 },
    { 20, -1, 22, -1, 10, 4, 0, -1, -1, -1, 11, 5, 2, -1, -1, -1, 6, -1, 12, -1, 16, -1, 18, -1 },
    { -1, 21, -1, 23, -1, -1, -1, 1, 9, 15, -1, -1, -1, 3, 8, 14, -1, 7, -1, 13, -1, 17, -1, 19 },
    { -1, -1, 11, 5, -1, 16, 12, 6, 2, -1, -1, 17, 13, 7, 3, -1, 14, 8, -1, -1, -1, -1, -1, -1 }
};

int count(vector<int>& mat)
{
    return  mat[0] * mat[1] * mat[2] * mat[3] +
            mat[4] * mat[5] * mat[10] * mat[11] +
            mat[6] * mat[7] * mat[12] * mat[13] +
            mat[8] * mat[9] * mat[14] * mat[15] +
            mat[16] * mat[17] * mat[18] * mat[19] +
            mat[20] * mat[21] * mat[22] * mat[23];
}

void change(vector<int>& mat, int dir)
{
    vector<int> new_mat = mat;
    for (int i = 0; i < 24; i++)
        if (rot[dir][i] != -1)
            new_mat[i] = mat[rot[dir][i]];
    mat = new_mat;
}

void dfs(vector<int>& mat, int time)
{
    res = max(res, count(mat));
    if (time <= 0) return;

    auto origin = mat;
    for (int i = 0; i < 6; i++)
    {
        change(mat, i);
        dfs(mat, time - 1);
        change(mat, i); 
        change(mat, i);
        dfs(mat, time - 1);
        mat = origin;
    }
}

int main()

{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    vector<int> mat(24);
    for(int i = 0; i < 24; i++)
        cin >> mat[i];
    
    dfs(mat, 5);

    cout << res << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}