// Problem: https://www.acwing.com/problem/content/1252/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 210;
int n, m;
int p[N * N];

// 将二维坐标转换为一维坐标（xy从0开始）
int get(int x, int y) {
    return x * n + y;
}

// 并查集基本操作：求祖宗节点（顺便实现了路径压缩）
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n >> m;
    // 并查集初始化
    for (int i = 0; i < n * n; i++)
        p[i] = i;

    int res = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        x--, y--;  // 坐标修正为从0开始
        int a = get(x, y);
        int b;
        // 计算下一个点的坐标
        if (d == 'D')
            b = get(x + 1, y);
        else
            b = get(x, y + 1);

        // 求 a 和 b 的祖宗节点
        int pa = find(a), pb = find(b);
        // 如果祖宗节点相同，说明 a 和 b 已经在一个集合了。
        // 那么加入这条边，直接就形成闭环了
        if (pa == pb) {
            res = i;
            break;
        }

        // 把 a 集合加入 b 集合
        p[pa] = pb;
    }

    if (!res)
        cout << "draw" << endl;
    else
        cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}