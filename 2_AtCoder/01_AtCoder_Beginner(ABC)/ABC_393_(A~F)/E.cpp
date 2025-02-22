// Problem: https://atcoder.jp/contests/abc393/tasks/abc393_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1.2e6 + 10;

int n, k;
int a[N];
int cnt[N];   // 记录每个数字在 a 中出现的次数
int mult[N];  // 记录 a 中 x 的倍数的个数
int res[N];   // 记录每个数字对应的最大公约数

void solve() {
    // 读取数据，同时记录每个数字出现的次数
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }

    // 对于每一个数字x，记录数字x的倍数在 a 中出现了多少次
    for (int x = 1; x < N; x++)
        for (int y = x; y < N; y += x)
            mult[x] += cnt[y];

    // 对于每一个数字 d，如果 d 的倍数在 a 中出现的次数超过 k 次
    // 说明 d 可以是所有 d 的倍数的 ai 的答案
    for (int d = 1; d < N; d++) {
        if (mult[d] < k)
            continue;
        for (int ai = d; ai < N; ai += d)
            res[ai] = max(res[ai], d);
    }

    // 最后输出每一个 ai 对应的结果
    for (int i = 1; i <= n; i++)
        cout << res[a[i]] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}