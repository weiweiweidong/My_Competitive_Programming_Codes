// Problem: https://atcoder.jp/contests/abc138/tasks/abc138_d
// 2024-12-04
/*
简单的 DFS 应用。
DFS 的时候，整张图每个节点只会被遍历一次，所以DFS 部分时间复杂度是O(n)。

整体时间复杂度为 O(N建图+Q读入查询+N深搜)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n, q;
int v[N];          // 存储各点的值
vector<int> e[N];  // 邻接表存储树

/*
    深搜
        now：当前要看的节点
        fa：father 父节点
        son：子节点
*/
void dfs(int now, int fa) {
    for (int son : e[now]) {
        // 为了避免搜到父节点，需要特判
        if (son != fa) {
            v[son] += v[now];
            dfs(son, now);
        }
    }
}

void solve() {
    cin >> n >> q;
    // 建树
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b), e[b].push_back(a);
    }

    // 读入每个点的值
    for (int i = 1; i <= q; i++) {
        int p, x;
        cin >> p >> x;
        v[p] += x;
    }

    // 从 1 节点开始深搜
    dfs(1, -1);

    // 输出结果
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}