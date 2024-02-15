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

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<char>> grid(H, vector<char>(W, '.'));

    int x = 0, y = 0, direction = 0;
    while (N--) {
        if (grid[x][y] == '.') {
            grid[x][y] = '#';
            direction = (direction + 4 + 1) % 4;
            x = (x + H + dx[direction]) % H, y = (y + dy[direction] + W) % W;

        } else if (grid[x][y] == '#') {
            grid[x][y] = '.';
            direction = (direction + 4 - 1) % 4;
            x = (x + H + dx[direction]) % H, y = (y + dy[direction] + W) % W;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << grid[i][j];
        cout << endl;
    }
}