// Problem: https://atcoder.jp/contests/abc386/tasks/abc386_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, m;
struct Node {
    int x, y;
    char c;
} p[N];

bool cmp(const Node& a, const Node& b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i].x >> p[i].y >> p[i].c;

    // 让格子升序排列
    sort(p, p + m, cmp);

    // min_y 初始化
    int min_y = 1e9 + 10;
    // 遍历所有的格子
    for (int i = 0; i < m; i++) {
        // 如果是白色：维护min_y，即白色出现在最左侧的位置
        if (p[i].c == 'W')
            min_y = min(min_y, p[i].y);
        // 如果是黑色格子，并且 y 值超过了 min_y，说明条件不成立
        else if (p[i].y >= min_y) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}