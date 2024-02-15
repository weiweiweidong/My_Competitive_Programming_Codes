#include <math.h>
#include <string.h>
#include <algorithm>
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

typedef long L;
typedef long long LL;
using namespace std;

typedef pair<int, int> PII;
const int SIZE = 65;

int N;
char Graph[SIZE][SIZE];            // 网格
int Dist[SIZE][SIZE][SIZE][SIZE];  // 判断两个点之间的距离
int Vis[SIZE][SIZE][SIZE][SIZE];   // 判断两个点有没有走到这个状态
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
// 设置一个数据格式，里面包含两个点的坐标
struct Node {
    int X1, Y1, X2, Y2;
};
// bfs
void bfs(int sx1, int sy1, int sx2, int sy2) {
    // 初始化
    memset(Vis, 0, sizeof Vis);
    memset(Dist, 0x3f, sizeof Dist);
    // 设置队列
    queue<Node> Q;
    Q.push({sx1, sy1, sx2, sy2});
    // 设置起点距离为0
    Dist[sx1][sy1][sx2][sy2] = 0;

    while (Q.size()) {
        // 取出队头
        auto t = Q.front();
        Q.pop();

        // 如果这个状态已经被遍历过了，跳掉
        if (Vis[t.X1][t.Y1][t.X2][t.Y2])
            continue;
        // 负责设置这个状态为1
        Vis[t.X1][t.Y1][t.X2][t.Y2] = 1;

        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            // 设置新的点的坐标
            int xx1 = t.X1 + dx[i], yy1 = t.Y1 + dy[i];
            int xx2 = t.X2 + dx[i], yy2 = t.Y2 + dy[i];

            // 将异常值排除掉
            xx1 = max(1, xx1), yy1 = max(1, yy1), xx1 = min(xx1, N),
            yy1 = min(yy1, N);
            xx2 = max(1, xx2), yy2 = max(1, yy2), xx2 = min(xx2, N),
            yy2 = min(yy2, N);

            // 如果对应的点是障碍物，就不移动
            if (Graph[xx1][yy1] == '#')
                xx1 = t.X1, yy1 = t.Y1;
            if (Graph[xx2][yy2] == '#')
                xx2 = t.X2, yy2 = t.Y2;
            // 否则就更新位置信息
            Dist[xx1][yy1][xx2][yy2] =
                min(Dist[xx1][yy1][xx2][yy2], Dist[t.X1][t.Y1][t.X2][t.Y2] + 1);
            // 将状态存进队列
            Q.push({xx1, yy1, xx2, yy2});
        }
    }
}

signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);

    // 读入数据，并找到两个玩家的位置
    cin >> N;
    int X1 = 0, Y1, X2, Y2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Graph[i][j];
            if (Graph[i][j] == 'P' && !X1)
                X1 = i, Y1 = j;
            else if (Graph[i][j] == 'P')
                X2 = i, Y2 = j;
        }
    }

    // 开始 BFS
    bfs(X1, Y1, X2, Y2);
    // 遍历所有点，看同时达到 ij 点时候的最短距离
    int Result = 1e9;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Result = min(Result, Dist[i][j][i][j]);
        }
    }
    // 输出结果
    if (Result == 1e9)
        cout << -1 << endl;
    else
        cout << Result << endl;
}