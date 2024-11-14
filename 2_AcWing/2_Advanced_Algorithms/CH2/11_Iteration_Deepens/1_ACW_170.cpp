// Problem: https://www.acwing.com/problem/content/172/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n;
int path[N];

// 参数：
// u：当前要填的位置
// k：需要生成的数列长度
bool dfs(int u, int k) {
    if (u == k)
        // 判断一下数列中最后被填入的那个数字，是不是等于 n
        return path[u - 1] == n;

    bool st[N] = {0};  // 将整个数组初始化为 0

    // 目标：给 u 这个位置填入数字
    // 尝试所有可能的数对组合
    for (int i = u - 1; i >= 0; i--)
        for (int j = i; j >= 0; j--) {
            // 求出数对和
            int s = path[i] + path[j];

            /*
            剪枝条件：
                1.和大于目标值 n
                2.和小于等于前一个数（要保证整条数列单调递增，所以不可能生成比path[u-1]）小的数
                3.这个数已经被用过了
            */
            if (s > n || s <= path[u - 1] || st[s])
                continue;

            // 给 u 位置填入 s，并把 s 标记用过
            st[s] = true;
            path[u] = s;

            // 向下搜下一个位置
            if (dfs(u + 1, k))
                return true;
        }
    return false;
}

void solve() {
    // 第一个数永远是 1
    path[0] = 1;

    while (cin >> n, n) {
        int k = 1;
        // 如果能搜出来第 k 层，就继续往下搜第 k+1 层
        while (!dfs(1, k))
            k++;

        // 输出整条路径
        for (int i = 0; i < k; i++)
            cout << path[i] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}