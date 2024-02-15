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

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> grid(H + 1, vector<char>(W + 1, ' '));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> grid[i][j];
        }
    }

    // 预处理数据
    vector<vector<int>> point(H + 1, vector<int>(W + 1, 0));
    vector<vector<int>> obstacle(H + 1, vector<int>(W + 1, 0));
    vector<vector<int>> circle(H + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '.')
                point[i][j]++;
            if (grid[i][j] == 'o')
                circle[i][j]++;
            if (grid[i][j] == 'x')
                obstacle[i][j]++;
        }
    }

    // 计算二维前缀和
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            point[i][j] +=
                point[i - 1][j] + point[i][j - 1] - point[i - 1][j - 1];
            obstacle[i][j] += obstacle[i - 1][j] + obstacle[i][j - 1] -
                              obstacle[i - 1][j - 1];
            circle[i][j] +=
                circle[i - 1][j] + circle[i][j - 1] - circle[i - 1][j - 1];
        }
    }

    // 开始遍历所有的点
    int res = 2e8;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == 'x')
                continue;

            // 分别计算上方和左方有多少
            // 上方
            if (i - K >= 0) {
                // 计算上方有多少x
                int ob = obstacle[i][j] - obstacle[i][j - 1] -
                         obstacle[i - K][j] + obstacle[i - K][j - 1];
                // 如果没有x，就计算需要多少次操作（即，有多少个.）
                if (ob == 0) {
                    int change = point[i][j] - point[i][j - 1] -
                                 point[i - K][j] + point[i - K][j - 1];
                    res = min(res, change);
                }
            }
            // 左方
            if (j - K >= 0) {
                // 计算左方有多少x
                int ob = obstacle[i][j] - obstacle[i][j - K] -
                         obstacle[i - 1][j] + obstacle[i - 1][j - K];
                // 如果没有x，就计算需要多少次操作（即，有多少个.）
                if (ob == 0) {
                    int change = point[i][j] - point[i][j - K] -
                                 point[i - 1][j] + point[i - 1][j - K];
                    res = min(res, change);
                }
            }
        }
    }

    if (res == 2e8)
        cout << "-1" << endl;
    else
        cout << res << endl;
}