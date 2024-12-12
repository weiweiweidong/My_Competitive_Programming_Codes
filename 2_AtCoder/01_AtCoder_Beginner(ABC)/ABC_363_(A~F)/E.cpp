// Problem: https://atcoder.jp/contests/abc363/tasks/abc363_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct Node {
    int x, y, t;
    bool operator<(const Node& a) const { return t > a.t; }
};
priority_queue<Node> Q;
const int N = 1010;
int H, W, Y;
int A[N][N];
bool st[N][N];
int res[100010];

void solve() {
    // 读入数据
    cin >> H >> W >> Y;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> A[i][j];

    // 把边缘的格子加入小根堆
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            if (i == 1 || j == 1 || i == H || j == W) {
                st[i][j] = true;
                Q.push((Node){i, j, A[i][j]});
            }

    int T = 0;
    while (Q.size()) {
        // 拿出当前最低的格子
        Node now = Q.top();
        Q.pop();
        int x = now.x, y = now.y, t = now.t;
        T = max(T, t);
        res[T]++;  // T 高度被淹的格子数量+1

        // 看一下这个格子周围的四个方向
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            // 越界
            if (a < 1 || a > H || b < 1 || b > W)
                continue;
            // 已经在队列中
            if (st[a][b])
                continue;

            // 入队
            Q.push((Node){a, b, A[a][b]});
            st[a][b] = true;
        }
    }

    // 计算前缀和（已知i时刻淹了的格子数量，就知道0~i时刻总共被淹的格子数量）
    for (int i = 1; i <= Y; i++)
        res[i] += res[i - 1];
    // 输出结果
    for (int i = 1; i <= Y; i++)
        cout << H * W - res[i] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}