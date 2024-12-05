// Problem: https://atcoder.jp/contests/abc351/tasks/abc351_d
// 2024-12-04
// DFS 最大连通区域问题

/*
    本解法的关键是：将网格构建成一张有向图
    所有的格子都可以视为一个节点，坐标转换 index = xw+y
    分成三种格子：
        # : 直接跳过，不设置成节点
        #周围的. : 设置成节点，但是只有入边，没有出边
        剩余的 . : 节点，并且向四方向出边
    Reference：https://atcoder.jp/contests/abc351/editorial/9889
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int h, w;
string g[N];       // 储存网格
vector<int> e[N];  // 建图
int used[N];       // 记录每个点的连通域编号，未使用为-1
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int cnt, res;  // cnt当前连通域尺寸，res 为最终答案

void dfs(int s, int u) {
    // 如果 u 点就是现在的连通域编号，说明用过了，直接退出
    if (used[u] == s)
        return;
    // 标记
    used[u] = s;
    cnt++;
    // 遍历周围的点，向下继续搜
    for (auto next : e[u])
        dfs(s, next);
    // 结束
    return;
}

void solve() {
    // 读入数据
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> g[i];

    // 建图！！！！！！！
    for (int x = 0; x < h; x++)
        for (int y = 0; y < w; y++) {
            if (g[x][y] == '#')
                continue;

            bool can = true;
            // 将周围四个格子加入图中
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= h || b < 0 || b >= w)
                    continue;
                if (g[a][b] == '#')
                    can = false;
                e[x * w + y].push_back(a * w + b);
            }
            // 如果遇到#，说明不能跳了，把边删除
            if (!can)
                e[x * w + y].clear();
        }

    // 初始化
    memset(used, -1, sizeof used);

    // DFS
    for (int x = 0; x < h; x++)
        for (int y = 0; y < w; y++) {
            if (g[x][y] == '#')
                continue;
            cnt = 0;
            dfs(x * w + y, x * w + y);
            res = max(res, cnt);
        }

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}