// Problem: https://www.acwing.com/problem/content/192/

/*
！！！！重要：
本题目在本地环境中无法正常运行，问题出在数据输入的：
    while (cin >> a[n] >> b[n])
        n++;
在本地中无法正常退出。需要在网页端才能测试。但是下面的代码本身是正确的。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 6;
int n;
string A, B;
string a[N], b[N];

int extend(queue<string>& q,                // 当前方向的队列
           unordered_map<string, int>& da,  // 当前方向的距离记录
           unordered_map<string, int>& db,  // 另一方向的距离记录
           string a[N],                     // 变换规则
           string b[N]) {
    int d = da[q.front()];  // 获取当前层的距离
    // 处理当前层的所有节点
    while (q.size() && da[q.front()] == d) {
        auto t = q.front();
        q.pop();
        // 遍历每一种转换操作
        for (int i = 0; i < n; i++)
            // 遍历 now 中的每一个位置
            for (int j = 0; j < t.size(); j++)
                // 如果刚好和变换字符串相匹配
                if (t.substr(j, a[i].size()) == a[i]) {
                    // 构建转换后的字符串
                    string r =
                        t.substr(0, j) + b[i] + t.substr(j + a[i].size());
                    // 如果转换后的字符串存在于 db 中，就直接计算出总路径长度
                    if (db.count(r))
                        return da[t] + db[r] + 1;
                    // 如果新的字符串已经在 da 中出现过，直接 pass
                    if (da.count(r))
                        continue;
                    // 更新新字符串距离
                    da[r] = da[t] + 1;
                    q.push(r);
                }
    }

    return 1234;  // 返回一个很大的数字，表明这一层没有相遇的状态
}

int bfs() {
    if (A == B)
        return 0;
    // 存储两个方向的扩展
    queue<string> qa, qb;
    // 存储两个方向状态的步数
    unordered_map<string, int> da, db;
    // 初始化
    qa.push(A), qb.push(B);
    da[A] = db[B] = 0;

    int step = 0;
    // 只有qa和qb都有值的时候才能两边做扩展。如果只有一方有扩展，另一方已经为空了，说明从A开始的集合和从B开始的集合不连通，题目无解
    while (qa.size() && qb.size()) {
        int t;
        // 从尺寸小的方向开始扩展，可以减少计算量
        if (qa.size() < qb.size())
            t = extend(qa, da, db, a, b);
        else
            t = extend(qb, db, da, b, a);

        if (t <= 10)  // 说明状态能相遇/有重合点
            return t;
        if (++step == 10)  // step++，要将总长度控制在 10 步以内
            return -1;
    }
    return -1;
}

void solve() {
    cin >> A >> B;
    while (cin >> a[n] >> b[n])
        n++;

    int t = bfs();
    if (t == -1)
        puts("NO ANSWER!");
    else
        cout << t << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}