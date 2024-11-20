// Problem: https://www.acwing.com/problem/content/5566/
// 拓扑排序的应用
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = 30;
int n;
string s[N];
bool g[M][M];
int q[M], d[M];

bool work(string& a, string& b) {
    // 找到两个字符串的第一个不同的字符，建图
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            int x = a[i] - 'a', y = b[i] - 'a';
            g[x][y] = true;
            return true;
        }
    }
    // 特例判断
    // 1. 如果两个字符串是 b 和 bb，是符合逻辑的，返回true
    // 2. 如果两个字符串是 bb 和 b，是不符合逻辑的，返回false
    // 3. 如果两个字符串是 bb 和 bb，是不符合逻辑的，返回false
    return a < b;
}

// 拓扑排序
bool topsort() {
    // 队列初始化
    int hh = 0, tt = -1;
    // 先把所有入度为0的字符入队
    for (int i = 0; i < 26; i++)
        if (!d[i])
            q[++tt] = i;

    // BFS
    while (hh <= tt) {
        int now = q[hh++];
        // 遍历和 now 点相连的所有点
        for (int next = 0; next < 26; next++) {
            if (g[now][next]) {
                d[next]--;
                // 如果入度变成了0，入队
                if (!d[next])
                    q[++tt] = next;
            }
        }
    }
    // 如果最后队列的长度为25，说明没有子环，可以拓扑排序正常运作
    return tt == 25;
}

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    // 建图
    for (int i = 1; i < n; i++)
        if (!work(s[i - 1], s[i])) {
            cout << "Impossible" << endl;
            return;
        }
    // 计算每个点的入度
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (g[i][j])
                d[j]++;

    // 执行拓扑排序
    bool flag = topsort();
    if (!flag)
        cout << "Impossible" << endl;
    else {
        for (int i = 0; i < 26; i++)
            cout << (char)(q[i] + 'a');
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}