// Problem: https://atcoder.jp/contests/abc384/tasks/abc384_f

#include <bits/stdc++.h>
using namespace std;
// typedef long long LL;
#define int long long  // 本题中大量使用 ll，为了方便直接定义为 int
typedef pair<int, int> PII;

const int N = 2e5 + 10, M = 2e7 + 10;
int n;
int a[N];
int sum[M];  // 存储累计和，A_i的上限是2e7，所以mp的idx不会超过这个数
int cnt[M];  // 存储计数
int d[30];   // 存储所有中间的 d 值

void solve() {
    // 读入原始数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int k = 1;  // 即 2^0
    // 遍历阶次
    for (int j = 0; j <= 24; j++) {
        // 从头遍历数组中的每个数
        for (int i = 1; i <= n; i++) {
            int key = a[i] % k;
            // mp[r]是a[i]%k后余数为r的所有数a[i]的累计和
            sum[key] += a[i];
            // cnt[r]是a[i]%k后余数为r的所有数出现次数
            cnt[key]++;
            // 累计获得 d_j 的值
            d[j] += sum[(k - a[i] % k) % k] + a[i] * cnt[(k - a[i] % k) % k];
        }
        // mp 与 cnt 重置
        for (int i = 1; i <= n; i++) {
            int key = a[i] % k;
            sum[key] = 0;
            cnt[key] = 0;
        }
        k = k * 2;
    }

    // 计算出结果
    int res = 0;
    k = 1;
    for (int i = 0; i <= 24; i++) {
        res += (d[i] - d[i + 1]) / k;
        k *= 2;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}