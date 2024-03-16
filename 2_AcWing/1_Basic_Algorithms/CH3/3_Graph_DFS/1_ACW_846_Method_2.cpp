// Problem: https://www.acwing.com/problem/content/848/
// 使用 vector 来构建邻接表
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
vector<int> graph[N];
bool st[N];
int n;
int ans = N;

void add(int a, int b) {
    graph[a].push_back(b);
}

int DFS(int u) {
    st[u] = true;
    int sum = 1, res = 0;
    for (auto next : graph[u]) {
        if (!st[next]) {
            int s = DFS(next);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);

    return sum;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
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