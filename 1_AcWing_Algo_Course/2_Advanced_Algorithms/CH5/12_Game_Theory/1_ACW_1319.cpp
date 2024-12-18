// Problem: https://www.acwing.com/problem/content/1321/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, M = 6010;
int h[N], e[M], ne[M], idx;
int f[N];
int n, m, k;

// 添加边
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

/*
计算节点 u 的 sg 值
    如果 u 无法走向其他状态，则 u 的 sg 值为 0
    否则，u 的 sg 值为所有后继状态的 sg 值中不在该集合中的最小非负整数
*/
int sg(int u) {
    // 记忆化搜索。如果这个值已经被算过了，就直接输出
    if (f[u] != -1)
        return f[u];

    // 记录所有后续状态的 sg 值
    set<int> S;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        S.insert(sg(j));
    }

    // 找到不在后继 sg 集合中的最小非负整数，更新f[u]的值
    for (int i = 0;; i++)
        if (S.count(i) == 0) {
            f[u] = i;
            break;
        }
    // 返回结果
    return f[u];
}

void solve() {
    cin >> n >> m >> k;

    // 建图
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    // f 初始化
    memset(f, -1, sizeof f);

    // 读入每个棋子的位置
    int res = 0;
    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        res ^= sg(u);  // 对每个棋子的结果求异或和运算
    }

    // 输出结果
    if (res)
        cout << "win" << endl;
    else
        cout << "lose" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}