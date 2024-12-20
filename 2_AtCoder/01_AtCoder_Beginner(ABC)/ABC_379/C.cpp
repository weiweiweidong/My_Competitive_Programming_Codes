// Problem: https://atcoder.jp/contests/abc379/tasks/abc379_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

LL n, m;
struct Node {
    LL x;  // 存储位置
    LL a;  // 存储石子数量
} stone[N];

bool cmp(const Node& a, const Node& b) {
    return a.x < b.x;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> stone[i].x;
    for (int i = 0; i < m; i++)
        cin >> stone[i].a;

    // 升序排列
    sort(stone, stone + m, cmp);

    LL sum = 0;      // 记录石子数量的累计和
    LL pos_sum = 0;  // 记录累计的位置和

    for (int i = 0; i < m; i++) {
        // 如果石子的累计数量 无法填满前面的空格，结束程序
        if (sum < stone[i].x - 1) {
            cout << -1 << endl;
            return;
        }

        sum += stone[i].a;                   // 更新石子数量的累计和
        pos_sum += stone[i].x * stone[i].a;  // 更新累计的位置和
    }

    // 如果石子数量不对
    if (sum != n) {
        cout << -1 << endl;
        return;
    }

    // 输出结果
    cout << n * (n + 1) / 2 - pos_sum << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}