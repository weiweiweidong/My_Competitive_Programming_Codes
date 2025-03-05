// Problem: https://atcoder.jp/contests/abc128/tasks/abc128_c

// Bit Complete Search
/*
    思路：
        有n个开关，可以用一个 n 位的二进制数来表示开关状态。
        枚举每一个灯泡对应的各个开关状态，计算打开开关的总数量cnt。
        如果 cnt%2 == p，说明当前状态能符合当前灯泡的要求。
        如果不符合,这个状态就不用继续搜了。

        m 最大为 10 位，整个状态空间最大 2^10=1024，非常小
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 12;
vector<int> bulb[N];  // 存储每个灯泡，连接着哪些开关
int p[N];             // 记录每个灯泡对应的模
int n, m;             // 有 n 个开关，m 个灯泡
int k, s;             // 临时变量

void solve() {
    cin >> n >> m;
    // 读入和每个灯泡相连接的开关编号
    for (int i = 0; i < m; i++) {
        cin >> k;
        while (k--) {
            cin >> s;
            bulb[i].push_back(s - 1);
        }
    }
    // 记录每个灯泡对应的模数
    for (int i = 0; i < m; i++)
        cin >> p[i];

    int res = 0;
    // 枚举所有开关状态
    for (int st = 0; st < (1 << n); st++) {
        bool can = true;
        // 枚举各个灯泡
        for (int b = 0; b < m; b++) {
            // 记录开灯个数
            int cnt = 0;
            // 枚举所有跟 b 灯泡相连的开关编号
            for (auto x : bulb[b])
                // 如果x开关是开着的状态
                if (st >> x & 1)
                    cnt++;
            // 如果开着的开关数 模2 不等于 p，说明当前状态不符合要求
            if (cnt % 2 != p[b]) {
                can = false;
                break;
            }
        }
        if (can)
            res++;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}