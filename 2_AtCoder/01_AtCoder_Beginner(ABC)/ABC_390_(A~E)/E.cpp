// Problem: https://atcoder.jp/contests/abc390/tasks/abc390_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5010;
int a[3][N], c[3][N];  // 记录每个食物的维生素的量 和 卡路里的量
int n, x;
int cnt[3];  // 记录三个维生素对应的食物的数量
// f[k][i][j] 表示第 i 个食物，在 j 卡路里下，能得到 k 维生素的最大值
int f[3][N][N];

bool check(int m) {
    int res = 0;
    for (int k = 0; k < 3; k++) {
        bool ok = false;
        // 遍历一下卡路里的可能性
        for (int i = 0; i <= x; i++) {
            // 如果只消耗 i 卡路里，就能摄取 m 的维生素
            if (f[k][cnt[k]][i] >= m) {
                res += i;
                ok = true;
                break;
            }
        }
        // 说明所有食物都吃掉了，维生素的量都不够 m，则返回 false
        if (!ok)
            return false;
    }
    // 如果三类都能达到，且总预算不超过 x，则返回 true
    return res <= x;
}

void solve() {
    // 读入数据
    cin >> n >> x;
    // 读入 1~n 的食物，按照维生素分成三组，分别存储维生素的量 a 和卡路里数 c
    for (int i = 1; i <= n; i++) {
        int v, A, C;
        cin >> v >> A >> C;
        v--;               // 维生素为 0,1,2
        cnt[v]++;          // 记录 v 号维生素的食物的数量
        a[v][cnt[v]] = A;  // 记录这个食物的维生素的量
        c[v][cnt[v]] = C;  // 记录这个食物的卡路里的量
    }

    // 遍历三种维生素
    for (int k = 0; k < 3; k++) {
        // 对于维生素 k，把 1~cnt[k] 的所有食物看一遍
        for (int i = 1; i <= cnt[k]; i++) {
            // 不选第 i 个食物，能获取的维生素的最大值
            // （这句略微有些难理解，下面两行就是解释）
            memcpy(f[k][i], f[k][i - 1], sizeof(f[k][i]));
            // for (int j = 0; j <= x; j++)
            //     f[k][i][j] = f[k][i-1][j];

            // 选第 i 个食物，更新获得的最大 k 维生素的量
            for (int j = c[k][i]; j <= x; j++) {
                f[k][i][j] =
                    max(f[k][i][j], f[k][i - 1][j - c[k][i]] + a[k][i]);
            }
        }
    }

    // 开始二分
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    // 输出结果
    cout << l << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}