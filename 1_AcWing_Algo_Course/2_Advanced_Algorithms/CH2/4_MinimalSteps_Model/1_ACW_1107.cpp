// Problem: https://www.acwing.com/problem/content/1109/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char g[2][4];
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;

// 字符串 -> 矩阵 g
void s2g(string state) {
    for (int i = 0; i < 4; i++)
        g[0][i] = state[i];
    for (int i = 7, j = 0; i >= 4; i--, j++)
        g[1][j] = state[i];
}

// 矩阵 g -> 字符串
string g2s() {
    string res;
    for (int i = 0; i < 4; i++)
        res += g[0][i];
    for (int i = 3; i >= 0; i--)
        res += g[1][i];
    return res;
}

// A 变换
string move0(string state) {
    s2g(state);
    for (int i = 0; i < 4; i++)
        swap(g[0][i], g[1][i]);
    return g2s();
}
// B 变换
string move1(string state) {
    s2g(state);
    int v0 = g[0][3], v1 = g[1][3];
    for (int i = 3; i > 0; i--)
        g[0][i] = g[0][i - 1], g[1][i] = g[1][i - 1];
    g[0][0] = v0, g[1][0] = v1;
    return g2s();
}
// C 变换
string move2(string state) {
    s2g(state);
    int v = g[0][2];
    g[0][2] = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = v;
    return g2s();
}

int bfs(string start, string end) {
    // 不要忘了这个特判
    if (start == end)
        return 0;

    queue<string> q;
    q.push(start);
    dist[start] = 0;

    while (q.size()) {
        auto now = q.front();
        q.pop();

        string next[3];
        next[0] = move0(now);
        next[1] = move1(now);
        next[2] = move2(now);

        for (int i = 0; i < 3; i++) {
            if (!dist.count(next[i])) {
                dist[next[i]] = dist[now] + 1;
                q.push(next[i]);
                pre[next[i]] = {(i + 'A'), now};
                if (next[i] == end)
                    return dist[next[i]];
            }
        }
    }
    return -1;
}

void solve() {
    string start, end;
    // 输入最终状态
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        end += (x + '0');
    }
    // 创建起始状态
    for (int i = 1; i <= 8; i++)
        start += (i + '0');

    // 开始 bfs，并求步数
    int res = bfs(start, end);
    cout << res << endl;

    // 倒序找到变换过程
    string seq;
    while (end != start) {
        seq += pre[end].first;
        end = pre[end].second;
    }
    // 将变换过程颠倒
    reverse(seq.begin(), seq.end());
    // 输出变换序列（特判：没有变换序列的时候不输出）
    if (res > 0)
        cout << seq << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}