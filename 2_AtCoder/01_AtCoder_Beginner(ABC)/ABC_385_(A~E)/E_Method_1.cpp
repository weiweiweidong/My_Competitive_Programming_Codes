// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10, M = 6e5 + 10;
int h[N], e[M], ne[M], idx;  // 存储图
int deg[N];                  // 存储所有节点的度数
int d[N], cnt;               // 存储中心点周围点的度数
int n;

// 加边
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void solve() {
    // h 数组初始化
    memset(h, -1, sizeof h);

    // 读入边数据，建边，同时计算各个点的度数
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        add(a, b), add(b, a);
        deg[a]++, deg[b]++;
    }

    int res = n;
    // 遍历每个点作为中心点
    for (int now = 1; now <= n; now++) {
        /*
            注意：这里有个坑。照理说 d 数组每次都应该清空再用。
            但是 memset d 重置为 0 要 O(N) 的时间复杂度。
            这里重置 d 的话，就会超时，程序 TLE
            实际上使用 cnt 来维护 d 的长度，不用重置也可以。
        */
        // memset(d, 0, sizeof d);
        cnt = 0;
        for (int j = h[now]; j != -1; j = ne[j]) {
            int next = e[j];       // 获取 now 周围的点
            d[cnt++] = deg[next];  // 记录点的度数
        }

        sort(d, d + cnt, greater<int>());  // 降序排列

        // 分别计算“雪花树”的尺寸，更新最少删除点的值
        for (int i = 1; i <= cnt; i++) {
            int tmp = 1 + i * d[i - 1];
            res = min(res, n - tmp);
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