#include <math.h>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

const int N = 2010;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string dir_c = "^>v<";
string grid[N];
int H, W;

struct Pt {
    int x, y;
} st, ed;

// 判断是否出界。出界返回true，没出界返回 false
bool out(int x, int y) {
    return x < 0 || x >= H || y < 0 || y >= W;
}
// 判断字符对应的方向
int get_dir(char x) {
    for (int i = 0; i < 4; i++)
        if (dir_c[i] == x)
            return i;
    return -1;
}

bool ban[N][N];
void solve() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S')
                st = {i, j};
            else if (grid[i][j] == 'G')
                ed = {i, j};
        }
    }

    // 处理哨兵
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int dir = get_dir(grid[i][j]);
            if (dir == -1)
                continue;
            ban[i][j] = true;
            Pt now = {i + dx[dir], j + dy[dir]};
            while (!out(now.x, now.y) && grid[now.x][now.y] == '.') {
                ban[now.x][now.y] = true;
                now.x += dx[dir];
                now.y += dy[dir];
            }
        }
    }

    // BFS
    queue<Pt> qq;
    qq.push(st);
    vector<vector<int>> dis(H, vector<int>(W, -1));
    dis[st.x][st.y] = 0;
    while (!qq.empty()) {
        Pt me = qq.front();
        qq.pop();
        for (int i = 0; i < 4; i++) {
            Pt you = {me.x + dx[i], me.y + dy[i]};
            if (out(you.x, you.y) || ban[you.x][you.y] ||
                grid[you.x][you.y] == '#')
                continue;
            if (dis[you.x][you.y] != -1)
                continue;
            dis[you.x][you.y] = dis[me.x][me.y] + 1;
            qq.push(you);
        }
    }

    cout << dis[ed.x][ed.y] << endl;
}

int main() {
    solve();
}
