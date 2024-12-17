// Problem: https://atcoder.jp/contests/abc384/tasks/abc384_e

// 优先队列 BFS
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int N = 510;
LL g[N][N];
LL P, Q;  // 记录起点坐标
LL H, W, X;
LL res;
bool st[N][N];  // 记录各个点是否进过优先队列

// 创建结构体
struct Node {
    LL x, y, score;
    // 重置小于符号（为小根堆做准备）
    bool operator<(const Node& a) const { return score > a.score; }
};
priority_queue<Node> que;

void solve() {
    // 读入数据
    cin >> H >> W >> X >> P >> Q;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            cin >> g[i][j];
        }

    // 初始化
    que.push((Node){P, Q, g[P][Q]});
    st[P][Q] = true;
    res = 0;

    // 优先队列 BFS
    /*
        注意：题目中要求，吸收单元格的 score 值必须严格小于 res/X
        这里直接使用上取整，即 score <(res+X-1)/X 即可满足要求
    */
    while (que.size() && (res == 0 || que.top().score < (res + X - 1) / X)) {
        Node now = que.top();
        que.pop();
        res += now.score;
        for (int i = 0; i < 4; i++) {
            int a = now.x + dx[i], b = now.y + dy[i];
            // 越界
            if (a < 1 || a > H || b < 1 || b > W)
                continue;
            // 已经被看过了
            if (st[a][b])
                continue;

            // 加入优先队列
            que.push((Node){a, b, g[a][b]});
            st[a][b] = true;
        }
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