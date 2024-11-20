// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, idx;
        scanf("%d%d", &idx, &n);
        printf("%d %d\n", idx, (n + 1) / 2);

        priority_queue<int> down;                           // 大根堆
        priority_queue<int, vector<int>, greater<int>> up;  // 小根堆

        int cnt = 0;
        // 开始逐个读入数据
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);

            // 插入 上堆 或者 下堆
            if (down.empty() || x <= down.top())
                down.push(x);
            else
                up.push(x);

            // 维护上下堆的尺寸
            if (down.size() > up.size() + 1) {
                up.push(down.top());
                down.pop();
            }
            if (up.size() > down.size()) {
                down.push(up.top());
                up.pop();
            }

            // 输出中位数
            if (i % 2) {
                printf("%d ", down.top());
                if (++cnt % 10 == 0)
                    puts("");
            }
        }
        if (cnt % 10)
            puts("");
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}