// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAX_N = 2e5 + 10;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int N, M;
int a[MAX_N], b[MAX_N];
unordered_map<int, unordered_set<int> > occupation;

bool check(int x, int y) {
    // 如果超出范围
    if (x < 1 || x > N || y < 1 || y > N)
        return false;
    return true;
}

void solve() {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
        occupation[a[i]].insert(b[i]);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 8; j++) {
            int next_a = a[i] + dx[j];
            int next_b = b[i] + dy[j];
            if (check(next_a, next_b)) {
                occupation[next_a].insert(next_b);
            }
        }
    }

    LL oc = 0;
    for (auto [x, S] : occupation)
        oc += (LL)S.size();

    cout << (LL)N * N - oc << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}