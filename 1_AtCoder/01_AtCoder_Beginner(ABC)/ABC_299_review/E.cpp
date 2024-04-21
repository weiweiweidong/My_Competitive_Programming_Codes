#include <math.h>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long L;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;
// 邻接表存储图。表示声明了一个N大小的数组，每个数组中的元素是vector<int>
vector<int> adj[N];
int dis[N][N];

void BFS(int i) {
    queue<int> q;
    q.push(i);
    dis[i][i] = 0;
    while (q.size()) {
        // 取出当前的点
        int now = q.front();
        q.pop();
        // 遍历当前点的每一个临点
        for (int next : adj[now]) {
            // 如果数据已经被更新过了，就跳掉
            if (dis[i][next] != -1)
                continue;
            // 更新最短距离
            dis[i][next] = dis[i][now] + 1;
            q.push(next);
        }
    }
}

int main() {
    // 初始化dist数组。-1表示点与点之间的距离未知
    memset(dis, -1, sizeof dis);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // 对每一个点做一次BFS，更新出来点与点之间的最短距离。
    for (int i = 1; i <= n; i++)
        BFS(i);

    int k;
    cin >> k;
    vector<PII> condition;
    // 读入条件的数据
    for (int i = 0; i < k; i++) {
        int p, d;
        cin >> p >> d;
        condition.push_back({p, d});
    }
    int d[n + 1];
    // 初始化d数组，和初始字符串
    memset(d, 0x3f, sizeof d);
    string ans = string(n, '0');

    // 遍历每个点
    for (int i = 1; i <= n; i++) {
        bool ok = 1;
        // 如果 条件中的节点p到i节点距离 小于 要求条件：说明这个点不能被涂黑
        for (auto item : condition) {
            if (dis[item.first][i] < item.second)
                ok = 0;
        }
        // 如果这个点有涂黑的潜力：
        if (ok) {
            // 更新一下所有点到涂黑点的距离
            for (auto item : condition) {
                d[item.first] = min(d[item.first], dis[item.first][i]);
            }
            ans[i - 1] = '1';
        }
    }

    bool ok = 1;
    // 遍历一遍所有的条件
    for (auto item : condition) {
        if (d[item.first] != item.second)
            ok = 0;
    }

    if (!ok)
        cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << ans << endl;
    }
}