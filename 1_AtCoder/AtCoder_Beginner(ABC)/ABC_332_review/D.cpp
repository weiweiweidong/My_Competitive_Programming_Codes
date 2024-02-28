#include <math.h>
#include <string.h>
#include <algorithm>
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

map<vector<vector<int>>, int> dis;  // key：二维数组；val：距离

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A, B;
    A.assign(H, vector<int>(W));  // 将A初始化为 H行W列
    B.assign(H, vector<int>(W));
    // 输入数据
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }

    // 使用队列来存储每种状态
    queue<vector<vector<int>>> bfs;
    bfs.push(A);
    dis[A] = 0;
    while (!bfs.empty()) {
        // 获取队头的 A 状态
        auto now = bfs.front();
        // 弹出队头
        bfs.pop();
        // 如果 A 和 B 相同了，就输出距离
        if (now == B) {
            cout << dis[now] << endl;
            return 0;
        }
        // 从上到下依次互换两行
        for (int i = 0; i + 1 < H; i++) {
            auto tmp = now;
            swap(tmp[i], tmp[i + 1]);
            // 如果dis中还没有这个状态
            if (!dis.count(tmp)) {
                // 更新距离
                dis[tmp] = dis[now] + 1;
                // 把状态存到队列里
                bfs.push(tmp);
            }
        }
        // 从左到右依次互换两列
        for (int j = 0; j + 1 < W; j++) {
            auto tmp = now;
            for (int i = 0; i < H; i++) {
                swap(tmp[i][j], tmp[i][j + 1]);
            }
            // 如果 dis 中还没有这个新状态
            if (!dis.count(tmp)) {
                // 更新一下状态距离
                dis[tmp] = dis[now] + 1;
                // 把状态存到队列里
                bfs.push(tmp);
            }
        }
    }
    // 上面把所有的状态都遍历完了，程序没有输出，意味着 A 不可能转变为 B
    cout << "-1\n";
}