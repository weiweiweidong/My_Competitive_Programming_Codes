// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 150010;
int n, m;
// p表示并查集，s表示联通块内的点数，d表示联通块内的度数
int p[N], s[N], d[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

bool check() {
    // 遍历每个节点
    for (int i = 1; i <= n; i++) {
        // 如果是根节点
        if (p[i] == i)
            // 判断整个联通块的度数
            if (d[i] != (s[i] - 1ll) * s[i])
                return false;
    }
    return true;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i, s[i] = 1;

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        // 获取根节点，并更新根节点的度数
        a = find(a), b = find(b);
        d[a]++, d[b]++;
        // 如果a与b不在一个联通块内，就把b作为a的爹
        if (a != b) {
            // 把联通块内点数 和 度数 都更新到根节点上
            s[b] += s[a], d[b] += d[a];
            p[a] = b;
        }
    }

    if (check())
        puts("YES");
    else
        puts("NO");
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}