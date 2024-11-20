// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 30;
string words[N];  // 存储输入的所有单词
int g[N][N];  // 邻接矩阵，存储i单词结尾 与 j 单词开头的重叠长度
int used[N];  // 记录每个单词使用的次数
int res;      // 存储最长龙链的长度
int n;        // 单词的总数

void dfs(string dragon, int last) {
    res = max((int)dragon.size(), res);  // 更新最大长度

    // 标记使用
    used[last]++;

    // 搜索下一个可用的单词
    for (int i = 0; i < n; i++)
        if (g[last][i] && used[i] < 2)
            dfs(dragon + words[i].substr(g[last][i]), i);

    // 恢复原状
    used[last]--;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    char start;
    cin >> start;
    res = 0;

    // 预处理两个单词间的重合部分
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            string a = words[i], b = words[j];
            for (int k = 1; k < min(a.size(), b.size()); k++)
                // 若 a 的后 k 个字母 和 b 的前 k 个字母相同
                if (a.substr(a.size() - k, k) == b.substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
        }

    for (int i = 0; i < n; i++)
        if (words[i][0] == start)
            dfs(words[i], i);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}