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

int H, W;
vector<string> grid;
int res[110];

void search(int a, int b) {
    // 如果中心点不是 #
    if (grid[a][b] != '#')
        return;
    int d = 1;
    bool flag = true;
    while (flag) {
        int x1 = a - d, x2 = a + d, y1 = b - d, y2 = b + d;
        // 如果越界了
        if (x2 >= H || x1 < 0 || y2 >= W || y1 < 0) {
            flag = false;
            break;
        }
        // 如果四个角不是 #
        if (grid[x1][y1] != '#' || grid[x1][y2] != '#' || grid[x2][y1] != '#' ||
            grid[x2][y2] != '#') {
            flag = false;
            break;
        }
        d++;
    }
    res[d - 1]++;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#')
                search(i, j);
        }
    }

    for (int i = 1; i <= min(H, W); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}