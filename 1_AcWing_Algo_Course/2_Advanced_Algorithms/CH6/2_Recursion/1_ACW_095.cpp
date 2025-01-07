// Problem: https://www.acwing.com/problem/content/97/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 6;
char g[N][N], bg[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

// 按一下x行y列的开关，改变一次状态
void turn(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5)
            continue;
        g[a][b] ^= 1;
    }
}

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 5; i++) {
            scanf("%s", bg[i]);
        }

        int res = 10;
        for (int op = 0; op < 32; op++) {
            int cnt = 0;
            memcpy(g, bg, sizeof g);

            // 操作第一行的开关
            for (int i = 0; i < 5; i++) {
                if (op >> i & 1) {
                    turn(0, i);
                    cnt++;
                }
            }

            // 递推出第1～4行开关的状态
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 5; j++) {
                    if (g[i][j] == '0') {
                        turn(i + 1, j);
                        cnt++;
                    }
                }
            }

            // 检查最后一行灯是否全亮
            bool success = true;
            for (int i = 0; i < 5; i++)
                if (g[4][i] == '0')
                    success = false;

            if (success && res > cnt)
                res = cnt;
        }

        if (res > 6)
            res = -1;
        printf("%d\n", res);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}