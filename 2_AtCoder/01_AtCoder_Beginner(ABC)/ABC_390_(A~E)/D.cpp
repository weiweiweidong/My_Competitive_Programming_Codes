// Problem: https://atcoder.jp/contests/abc390/tasks/abc390_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
LL a[N];  // 存储原数组
LL b[N];  // 存储分组后的情况

int n;
// 存储结果，unordered_set 可以自动去重，同时不会有排序带来的额外开销
unordered_set<LL> S;

// DFS
// k：表示目前看到第 k 个数
// cnt：表示目前开了 cnt 个组
void dfs(int k, int cnt) {
    // 如果到底了，就开始算当前分组情况的 XOR 的值
    if (k > n) {
        LL res = 0;
        // 计算 XOR 值
        for (int i = 1; i <= cnt; i++)
            res ^= b[i];
        S.insert(res);
        return;
    }

    // 新开一组
    b[cnt + 1] = a[k];
    dfs(k + 1, cnt + 1);

    // 放入目前存在的一个组里
    for (int i = 1; i <= cnt; i++) {
        b[i] += a[k];  // 将a[k] 加入到当前组中
        dfs(k + 1, cnt);
        b[i] -= a[k];  // 恢复原状
    }
}

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 向下搜
    dfs(1, 0);

    // 输出结果
    cout << S.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}