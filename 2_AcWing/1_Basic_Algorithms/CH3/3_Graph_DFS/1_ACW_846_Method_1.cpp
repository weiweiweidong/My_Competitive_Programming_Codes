// Problem: https://www.acwing.com/problem/content/848/
// // 使用 数组模拟链表 来构建邻接表
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int n;
bool st[N];
int ans = N;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int DFS(int u) {
    st[u] = true;
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int next = e[i];
        if (!st[next]) {
            int s = DFS(next);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    DFS(1);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}