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

int judge(string version1, string version2)
{
    int pos1=0,len1=version1.length(),end1=0;
    int pos2=0,len2=version2.length(),end2=0;
    while(pos1<len1||pos2<len2){
        end1=pos1;
        end2=pos2;
        while(version1[end1]!='.'&&end1<len1) end1++;
        while(version2[end2]!='.'&&end2<len2) end2++;
        int s1,s2;
        if(pos1==end1) s1=0;
        else s1=stoi(version1.substr(pos1,end1-pos1));
        if(pos2==end2) s2=0;
        else s2=stoi(version2.substr(pos2,end2-pos2));
        
        if(s1>s2) return 1;
        else if(s1<s2) return -1;
        if(pos1<len1)
            pos1=end1+1;
        if(pos2<len2)
            pos2=end2+1;
    }
    return 0;
}

int main(int argc, const char *argv[])
{
    freopen("input.in", "r", stdin);

    string version1, version2;
    cin >> version1;
    cin >> version2;

    cout << judge(version1, version2) << endl;

    return 0;
}
