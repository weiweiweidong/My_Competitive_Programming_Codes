// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, p[200100];              // n是数组长度，p存储置换数组
long long k;                   // k表示操作次数
int cnt[200100], ans[200100];  // ans存储最终答案
bool vis[200100];              // 记录某个位置是否被访问过

// 快速幂，计算 a^k %m 的值
long long fpow(long long a, long long b, long long m) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return ans;
}

void solve() {
    cin >> n >> k;  // 输入n和k
    for (int i = 1; i <= n; i++)
        cin >> p[i];  // 输入置换数组

    // 找循环
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {      // 如果当前位置未被访问
            vector<int> c;  // 用来存储当前循环中的所有数
            int j = i;
            while (!vis[j]) {  // 沿着置换一直往下走，直到遇到已访问的数
                vis[j] = 1;      // 标记已访问
                c.push_back(j);  // 将当前数加入循环
                j = p[j];        // 移动到下一个数
            }
            int len = c.size();          // 循环的长度
            int temp = fpow(2, k, len);  // 计算2^k mod len

            // 计算k次操作后每个位置的新位置
            for (int j = 0; j < len; j++) {
                ans[c[j]] = c[(j + temp) % len];
            }

            // cout << "第一次循环：" << endl;
            // for (auto x : c)
            //     cout << x << " ";
            // cout << endl;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';  // 输出每个位置在k次操作后的新值
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}