#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct State {
    int x, y, energy;
};

bool bfs(const vector<string>& grid,
         const map<pair<int, int>, int>& medicines,
         int H,
         int W) {
    vector<vector<int>> visited(H, vector<int>(W, -1));
    queue<State> q;
    int sx, sy, tx, ty;

    // Find start and target positions
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }

    q.push({sx, sy, 0});
    visited[sx][sy] = 0;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.x == tx && curr.y == ty)
            return true;  // Reached target

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || grid[nx][ny] == '#')
                continue;  // Out of bounds or obstacle

            int nextEnergy = curr.energy - 1;
            auto it = medicines.find({nx, ny});
            if (it != medicines.end()) {  // Found medicine
                nextEnergy =
                    max(nextEnergy, it->second);  // Use medicine if beneficial
            }

            if (nextEnergy > visited[nx][ny]) {  // Can visit with more energy
                visited[nx][ny] = nextEnergy;
                q.push({nx, ny, nextEnergy});
            }
        }
    }

    return false;
}

int main() {
    int H, W, N;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
        cin >> grid[i];

    cin >> N;
    map<pair<int, int>, int> medicines;
    for (int i = 0; i < N; ++i) {
        int r, c, e;
        cin >> r >> c >> e;
        --r;
        --c;  // Adjusting to 0-based indexing
        medicines[{r, c}] = e;
    }

    cout << (bfs(grid, medicines, H, W) ? "Yes" : "No") << endl;

    return 0;
}
