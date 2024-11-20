// Problem: https://www.acwing.com/problem/content/181/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

typedef pair<int, string> PIS;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char op[4] = {'u', 'r', 'd', 'l'};

// 估价函数（用来评估当前状态到目标状态的距离，用于指导搜索朝着更有希望的方向进行）
int f(string state) {
    int res = 0;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != 'x') {
            // 数字 1 应该在位置 0，数字 2 应该在位置 1。。。
            int t = state[i] - '1';
            // i/3为当前数字的行，i%3为当前数字的列
            // t/3为目标位置的行，t%3为目标位置的列
            // 下面式子计算出了 行差绝对值 和 列差绝对值 的和
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}

string bfs(string start) {
    // 目标状态
    string end = "12345678x";
    unordered_map<string, int> dist;                 // 存储距离
    unordered_map<string, pair<string, char>> prev;  // 存储状态转移
    priority_queue<pair<int, string>, vector<pair<int, string>>,
                   greater<pair<int, string>>>
        heap;  // 小根堆

    heap.push({f(start), start});
    dist[start] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        string now = t.second;

        if (now == end)
            break;

        int step = dist[now];
        // 获得 'X' 符号的坐标
        int x, y;
        for (int i = 0; i < now.size(); i++)
            if (now[i] == 'x') {
                x = i / 3, y = i % 3;
                break;
            }

        // 四个方向
        for (int i = 0; i < 4; i++) {
            // 新的坐标
            int a = x + dx[i], b = y + dy[i];
            string next = now;
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                // 新状态
                swap(next[x * 3 + y], next[a * 3 + b]);
                // 如果新状态还没有见过 或 新状态的距离可以变得更小
                if (!dist.count(next) || dist[next] > step + 1) {
                    dist[next] = step + 1;
                    prev[next] = {now, op[i]};
                    heap.push({dist[next] + f(next), next});
                }
            }
        }
    }

    // 生成转换路径
    string res;
    while (end != start) {
        res += prev[end].second;  // 操作符号
        end = prev[end].first;    // 更新状态
    }
    reverse(res.begin(), res.end());
    return res;  // 返回结果
}

void solve() {  // g存储输入状态（包含x），c存储每个输入的字符，seq用于计算逆序对
    string g, c, seq;
    for (int i = 0; i < 9; i++) {
        cin >> c;
        g += c;
        if (c != "x")
            seq += c;
    }

    // 计算逆序对数量
    int t = 0;
    for (int i = 0; i < seq.size(); i++)
        for (int j = i + 1; j < seq.size(); j++)
            if (seq[i] > seq[j])
                t++;
    // 如果逆序对数量为奇数，则问题无解
    if (t % 2)
        puts("unsolvable");
    // 逆序对为偶数，就 bfs
    else
        cout << bfs(g) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}