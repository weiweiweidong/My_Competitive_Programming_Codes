// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, k;
int cost[N];

void bfs() {
    queue<int> q;
    q.push(n);
    cost[n] = 0;

    while (q.size()) {
        int now = q.front();
        q.pop();

        // 如果到终点了，跳出
        if (now == k)
            return;
        // 移动方式 1
        if (now + 1 < N && cost[now + 1] == -1) {
            q.push(now + 1);
            cost[now + 1] = cost[now] + 1;
        }
        // 移动方式 2
        if (now - 1 >= 0 && cost[now - 1] == -1) {
            q.push(now - 1);
            cost[now - 1] = cost[now] + 1;
        }
        // 移动方式 3
        if (2 * now < N && cost[2 * now] == -1) {
            q.push(2 * now);
            cost[2 * now] = cost[now] + 1;
        }
    }
}

void solve() {
    cin >> n >> k;

    memset(cost, -1, sizeof cost);
    bfs();
    cout << cost[k] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}