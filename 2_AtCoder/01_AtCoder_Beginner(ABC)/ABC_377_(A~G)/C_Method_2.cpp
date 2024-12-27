// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int a[N], b[N];  // 存储棋子的放置位置
set<PII> occupation;

bool check(int x, int y) {
    // 如果超出范围
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        // 将棋子的位置标记为已占用
        occupation.insert({a[i], b[i]});
    }

    // 存储每一个棋子的攻击范围
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 8; j++) {
            int next_a = a[i] + dx[j];
            int next_b = b[i] + dy[j];
            if (check(next_a, next_b))
                occupation.insert({next_a, next_b});
        }
    }

    // 计算剩下了多少位置
    LL res = (LL)n * n - occupation.size();
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}