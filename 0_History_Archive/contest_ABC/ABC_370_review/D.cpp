// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e5 + 10;
int n, m, q;
set<int> row[N], col[N];  // 对每行每列维护一个set

void remove(int x, int y) {
    row[x].erase(y);
    col[y].erase(x);
}

void place_bomb(int x, int y) {
    if (row[x].find(y) != row[x].end()) {
        remove(x, y);
        return;
    }

    auto it = row[x].lower_bound(y);
    if (it != row[x].end()) {
        remove(x, *it);
    }

    it = row[x].lower_bound(y);
    if (it != row[x].begin()) {
        --it;
        remove(x, *it);
    }

    it = col[y].lower_bound(x);
    if (it != col[y].end()) {
        remove(*it, y);
    }

    it = col[y].lower_bound(x);
    if (it != col[y].begin()) {
        --it;
        remove(*it, y);
    }
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        place_bomb(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += row[i].size();
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}