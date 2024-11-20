// Problem: https://www.acwing.com/problem/content/1108/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 1010;
int n;
int h[N][N];
bool st[N][N];

void bfs(int x, int y, bool& has_higher, bool& has_lower) {
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;

    while (q.size()) {
        PII t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int xx = t.first + dx[i], yy = t.second + dy[i];
            // 超出范围了
            if (xx < 1 || yy < 1 || xx > n || yy > n)
                continue;
            // 看一下和周围格子的关系
            // （注意，无论周围的格子有没有被遍历，都是要判断大小状态的）
            if (h[xx][yy] != h[t.first][t.second]) {
                if (h[xx][yy] > h[t.first][t.second])
                    has_higher = true;
                if (h[xx][yy] < h[t.first][t.second])
                    has_lower = true;
            }
            // 如果
            else if (!st[xx][yy]) {
                q.push({xx, yy});
                st[xx][yy] = true;
            }
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> h[i][j];

    int peak = 0, valley = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j]) {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher)
                    peak++;
                if (!has_lower)
                    valley++;
            }

    cout << peak << " " << valley << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}