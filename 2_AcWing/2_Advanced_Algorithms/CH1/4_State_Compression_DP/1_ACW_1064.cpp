// Problem: https://www.acwing.com/problem/content/1066/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = (1 << 10) + 20;
// state 存储合法状态；head[a] 表示 a 对应的的放置集合状态可以转移到的集合状态
vector<int> state, head[N];
int n, k;
LL f[12][110][N];
int cnt[N];

// 检查有没有出现相邻的两个1
bool check(int x) {
    for (int i = 0; i < n; i++)
        if ((x >> i & 1) && (x >> (i + 1) & 1))  // 第i位是1，而且第i+1位也是1
            return false;
    return true;
}
// O(1) 算法检查有没有出现相邻的两个1
/*
inline bool check2(int x) {
    return !(x & x >> 1);
}
*/

// 统计这个状态中有多少个1，即放置了多少个国王
int count(int x) {
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (x >> i & 1);
    return ans;
}

void pre() {
    // 第一步：找出满足不会左右攻击的合法放置国王的状态
    for (int i = 0; i < (1 << n); i++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    // 第二步：在可能的状态中进一步筛选，确定转移关系
    for (int i = 0; i < state.size(); i++) {
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            // 第一个条件检查上下攻击；第二个条件检查斜对角攻击
            if ((a & b) == 0 && check(a | b))
                // 说明下标为i的状态，能从下标为j的状态转移过来
                head[i].push_back(j);
        }
    }
}

void solve() {
    cin >> n >> k;
    pre();
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)  // n行转移，n+1行是为了好统计答案
        for (int j = 0; j <= k; j++)  // 目前使用的国王棋子数量
            for (int a = 0; a < state.size(); a++)
                for (int b = 0; b < head[a].size(); b++) {
                    // 统计state[a]对应的国王个数
                    int c = cnt[state[a]];
                    // 目前一共放j个国王，从b转移到a，要满足国王数不超标
                    if (j >= c)
                        f[i][j][a] += f[i - 1][j - c][head[a][b]];
                }

    // 第n+1行什么都不放，相当于只在1~n行放国王，目前共放了k个国王的总方案数，其实就是答案要求的方案
    cout << f[n + 1][k][0] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}