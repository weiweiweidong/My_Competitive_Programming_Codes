// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9 + 10;
const int N = 110;
int n;
char s[N][N];
int res[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> (s[i] + 1);

    memset(res, 0x3f, sizeof res);
    queue<PII> q;

    // 点到自己本身的距离为 0
    for (int i = 1; i <= n; i++) {
        q.push({i, i});  // 入队
        res[i][i] = 0;   // 距离为 0
    }

    // 有临边的，举例设为 1
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j || s[i][j] == '-')
                continue;
            q.push({i, j});
            res[i][j] = 1;  // 距离设为 1
        }

    // BFS
    // 备注：在某些情况下可能会卡常，STL 的 queue 比较花时间，可以手写一个 queue
    while (q.size()) {
        // 取出当前的路径
        auto now = q.front();
        q.pop();
        int u = now.first, v = now.second;
        // 遍历所有的点对
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                // 如果 i->u 或者 v->j 不相连，跳过
                if (s[i][u] == '-' || s[v][j] == '-')
                    continue;
                // 如果 i->j 距离已经被更新过，跳过
                if (res[i][j] != 0x3f3f3f3f)
                    continue;
                // 如果 i->u 与 v->j 的边的字母相同，说明可以入队
                if (s[i][u] == s[v][j]) {
                    res[i][j] = res[u][v] + 2;
                    q.push({i, j});
                }
            }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (res[i][j] == 0x3f3f3f3f ? -1 : res[i][j]) << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}