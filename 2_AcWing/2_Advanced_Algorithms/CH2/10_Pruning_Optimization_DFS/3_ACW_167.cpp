// Problem: https://www.acwing.com/problem/content/169/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 70;  // 木棍数量上限
int n;             // 实际的小木棍数量
int w[N];          // 小木棍长度
int sum, length;   // 所有木棍总长 和 目标长度
bool st[N];        // 记录木棍是否被用过

/*
参数含义：
    u：当前已经拼好了几根木棍
    cur：当前这根木棍已经拼好的长度
    start：从哪根木棍开始尝试（避免重复计算）
*/
bool dfs(int u, int cur, int start) {
    // 如果拼接总长度 等于 所有木棍总长，说明完成了拼接
    if (u * length == sum)
        return true;
    // 达成了目标长度，开始拼下一根
    if (cur == length)
        return dfs(u + 1, 0, 0);

    // 从 start 开始尝试没有使用的木棍
    for (int i = start; i < n; i++) {
        // 如果已经被用过 || 拼上就超过目标长度，就 continue
        if (st[i] || cur + w[i] > length)
            continue;

        st[i] = true;  // 标记使用
        // 继续往下走，如果这条路能走通，就返回 true
        if (dfs(u, cur + w[i], i + 1))
            return true;
        st[i] = false;  // 恢复原状

        /*
        头剪枝：
            如果 cur 为 0，说明这是第一根。但是走到这一步说明上面return false了
            所以这根木棒开头的可能都被遍历过了
            隐含意思是：这根木棒不能跟任何木棒组成规定长度的木棒
            也就不用继续往下搜了
        */
        if (!cur)
            return false;
        /*
        尾剪枝：
            如果这个木棒可以拼在另一个木棒下刚好达成目标值。但走到这一步，说明上面
        false 了。
        */
        if (cur + w[i] == length)
            return false;

        // 剪枝：跳过长度相同的木棍
        // 能走到这一步说明当前长度不行
        int j = i;
        while (j < n && w[j] == w[i])
            j++;
        i = j - 1;
    }
    return false;
}

void solve() {
    while (cin >> n, n) {
        memset(st, 0, sizeof st);
        sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> w[i];
            sum += w[i];
        }

        sort(w, w + n);
        reverse(w, w + n);

        length = 1;
        while (true) {
            if (sum % length == 0 && dfs(0, 0, 0)) {
                cout << length << endl;
                break;
            }
            length++;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}