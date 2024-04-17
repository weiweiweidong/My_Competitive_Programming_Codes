// Problem:
// 方法2 ：假设所有邮票全用一遍
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL N = 9, M = 20, K = 81, MOD = 998244353;
int n, m, k;
bool st[M];

// 计算结果值
LL calc(vector<vector<LL>>& A) {
    LL res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res += A[i][j];
    return res;
}

void solve() {
    // 弄一个随机数生成器
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 19);  // 随机生成一个邮票编号

    vector<vector<LL>> A(N, vector<LL>(N)), temp(N, vector<LL>(N)),
        A1(N, vector<LL>(N)), A2(N, vector<LL>(N)), A3(N, vector<LL>(N));
    array<array<LL, 3>, 3> stamps[M];

    // 输入数据
    cin >> n >> m >> k;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                cin >> stamps[i][j][k];
            }

    // 计算一下不放stamp时候的基准值
    LL res = calc(A);

    vector<array<int, 3>> ans;  // 插入摆放方案

    // 重复81次
    for (int t = 0; t < 400000 || ans.size() == 81; t++) {
        int k = dist(rng);  // 随机生成一个邮票编号
        if (st[k])
            continue;
        // for (int k = 19; k >= 0; k--) {
        vector<array<int, 3>> tmp_ans;  // 临时摆放方案
        LL tmp_res = res;               // 记录临时结果

        // 遍历棋盘上每一个点，试着找到当前邮票插入的最优位置
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++) {
                temp = A;  // 复制一份棋盘
                // 在这个位置放邮票
                for (int m = 0; m < 3; m++)
                    for (int n = 0; n < 3; n++)
                        temp[i + m][j + n] =
                            (temp[i + m][j + n] + stamps[k][m][n]) % MOD;
                LL res_now = calc(temp);
                if (tmp_res < res_now) {
                    tmp_ans.push_back({k, i, j});
                    tmp_res = res_now;
                }
            }

        if (res < tmp_res) {
            auto [a, b, c] = tmp_ans.back();
            // 在这个位置放邮票
            for (int m = 0; m < 3; m++)
                for (int n = 0; n < 3; n++)
                    A[b + m][c + n] = (A[b + m][c + n] + stamps[a][m][n]) % MOD;
            res = tmp_res;
            ans.push_back({a, b, c});
        }

        if (t > 1000 && res > tmp_res)
            st[k] = true;
        // }
    }

    cout << ans.size() << endl;
    for (auto [k, i, j] : ans) {
        cout << k << " " << i << " " << j << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}