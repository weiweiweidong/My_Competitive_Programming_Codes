// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 14, MOD = 1e8, M = (1 << 12);

int n, m;
int w[N];
vector<int> state;
vector<int> head[M];
int f[N][M];

// 快速判断有没有相邻的1
bool check(int x) {
    return !(x & (x >> 1));
}

void solve() {
    cin >> n >> m;  // n行m列
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            w[i] += !x * (1 << j);  // 荒废土地是0，我们在这里转换为1
        }

    for (int i = 0; i < (1 << m); i++)
        if (check(i))  // 这个状态不存在左右相邻的玉米
            state.push_back(i);

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if ((a & b) == 0)  // i对应的状态和j对应的状态没有上下相邻的玉米
                head[i].push_back(j);
        }

    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < state.size(); j++)
            // 如果 state 的状态 和 地图状态 1不重合
            if ((state[j] & w[i]) == 0)
                for (int k : head[j])
                    f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;

    cout << f[n + 1][0] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}