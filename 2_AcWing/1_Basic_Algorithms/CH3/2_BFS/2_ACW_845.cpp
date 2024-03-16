// Problem: https://www.acwing.com/problem/content/847/
// 八数码问题

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

queue<string> q;
unordered_map<string, int> d;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int BFS(string start) {
    string end = "12345678x";
    q.push(start);
    d[start] = 0;

    while (q.size()) {
        auto now = q.front();
        q.pop();
        int distance = d[now];
        if (now == end)
            return distance;

        int k = now.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3)
                continue;
            swap(now[k], now[3 * a + b]);
            if (!d.count(now)) {
                d[now] = distance + 1;
                q.push(now);
            }
            swap(now[k], now[3 * a + b]);
        }
    }
    return -1;
}

void solve() {
    string start;
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        start += c;
    }
    cout << BFS(start) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}