// Problem: https://atcoder.jp/contests/abc147/tasks/abc147_c
// 2024-12-04

/*
    题目类型非常经典：
    N 的总数并不大，最大 15 位。使用一个15位的二进制数即可表示所有人的状态
    使用 Bit全搜 也才是 2^15=32768 种可能性。
    对于每一个二进制数的状态，分别判断每一个判断条件是否和当前状态相矛盾。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

vector<int> honests[15];  // 存储每个人说谁是诚实的
vector<int> liars[15];    // 存储每个人说谁是说谎的
int N;

void solve() {
    cin >> N;  // 总人数
    for (int i = 0; i < N; i++) {
        int A;  // 读取第 i 个人说了几句话
        cin >> A;
        for (int j = 0; j < A; j++) {
            int x, y;
            cin >> x >> y;
            // y 为 0：表示 i 说 x 是说谎者
            if (y == 0)
                liars[i].push_back(x - 1);
            // y 为 1：表示 i 说 x 是诚实者
            else
                honests[i].push_back(x - 1);
        }
    }

    int ans = 0;
    // 使用二进制枚举15个人所有可能的情况：总共有 2^15=32768种，直接暴搜即可
    for (int msk = 0; msk < (1 << N); msk++) {
        bool ok = true;  // 标记当前假设是否合法
        int tot = 0;     // 标记当前情况下诚实人的数量
        for (int i = 0; i < N; i++) {
            // 每种情况下，假设第 i 个人是诚实的（即他说的话都是可信的）
            if (msk & (1 << i)) {
                tot++;
                // 遍历第 i 个人说的，哪些人是诚实的
                for (auto honest : honests[i])
                    // 如果i说honest这个人是诚实的，但是当前状态下honest不是，则判为异常
                    if (!(msk & (1 << honest)))
                        ok = false;
                // 遍历第 i 个人说的，哪些人是说谎的
                for (auto liar : liars[i])
                    // 如果i说honest这个人是不诚实的，但是当前状态下honest是诚实的，则判为异常
                    if (msk & (1 << liar))
                        ok = false;
            }
        }
        // 如果当前状态成立，就更新结果
        if (ok)
            ans = max(ans, tot);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}