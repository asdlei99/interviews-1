#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <queue>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
struct node {
    int x, y, step;
    node (int _x, int _y, int _step): x(_x), y(_y), step(_step) {} 
};

int shortestDistance(vector < vector < int > > map, vector < int > start, vector < int > dest) {
    queue<node> q;
    int n = map.size();
    int m = map[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    q.push(node(start[0], start[1], 0));

    int res = -1;
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    while(!q.empty() || res == -1)
    {
        node t = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dir[i][0];
            int ny = t.y + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || map[nx][ny]) continue;
            if (nx == dest[0] && ny == dest[1]) 
            {
                res = t.step + 1;
                break;
            }
            q.push(node(nx, ny, t.step + 1));
            visit[nx][ny] = 1;
        }
    }
    return res;
}
/******************************结束写代码******************************/


int main() {
    int res;
    // freopen("input.in", "r", stdin);
    int _map_rows = 0;
    int _map_cols = 0;
    cin >> _map_rows >> _map_cols;
    vector< vector < int > > _map(_map_rows);
    for(int _map_i=0; _map_i<_map_rows; _map_i++) {
        for(int _map_j=0; _map_j<_map_cols; _map_j++) {
            int _map_tmp;
            cin >> _map_tmp;
            _map[_map_i].push_back(_map_tmp);
        }
    }
    int _start_size = 0;
    cin >> _start_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _start;
    int _start_item;
    for(int _start_i=0; _start_i<_start_size; _start_i++) {
        cin >> _start_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _start.push_back(_start_item);
    }


    int _dest_size = 0;
    cin >> _dest_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _dest;
    int _dest_item;
    for(int _dest_i=0; _dest_i<_dest_size; _dest_i++) {
        cin >> _dest_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _dest.push_back(_dest_item);
    }


    
    res = shortestDistance(_map, _start, _dest);
    cout << res << endl;
    
    return 0;

}
