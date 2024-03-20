// Problem: https://atcoder.jp/contests/abc302/tasks/abc302_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N_MAX = 110;
string g[N_MAX];
int h, w;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check(int x, int y) {
    // 8个方向遍历
    for (int i = 0; i < 8; i++) {
        string s = "";
        bool flag = false;
        for (int j = 0; j < 5; j++) {
            int a = x + j * dx[i], b = y + j * dy[i];
            if (a < 0 || a >= h || b < 0 || b >= w) {
                flag = true;
                break;
            }
            s += g[a][b];
        }

        if (!flag && s == "snuke") {
            for (int j = 0; j < 5; j++) {
                int a = x + j * dx[i], b = y + j * dy[i];
                cout << a + 1 << " " << b + 1 << endl;
            }
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> g[i];

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (check(i, j))
                return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}