// Problem: https://atcoder.jp/contests/abc382/tasks/abc382_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n, m;
int A[N];
PII B[N];    // 存储食物美味度 和 食物编号
int res[N];  // 存储每个食物分给了谁

// 降序排列
bool cmp(const PII& a, const PII& b) {
    return a.first > b.first;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++) {
        cin >> B[i].first;  // 食物美味度
        B[i].second = i;    // 食物编号
    }

    sort(B, B + m, cmp);          // 降序排列
    memset(res, -1, sizeof res);  // res 初始化

    for (int i = 0, index = 0; i < n; i++) {
        // 只要 接受值 小于等于 食物美味度，就吃掉
        // index 如果超出 m 了，食物美味度就是 0，不影响后面的判断，不算越界
        while (A[i] <= B[index].first) {
            res[B[index].second] = i + 1;
            index++;
        }
    }

    // 输出结果
    for (int i = 0; i < m; i++)
        cout << res[i] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}