// Problem: https://www.acwing.com/problem/content/838/
// 朴素并查集
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int p[N];

// 求x的祖宗节点
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n >> m;
    // 并查集初始化
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if (*op == 'M')
            p[find(a)] = find(b);
        else {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}