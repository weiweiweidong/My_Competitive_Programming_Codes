#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N_MAX = 50;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int grid[N_MAX][N_MAX];
int st[N_MAX][N_MAX];
int N;

int main() {
    cin >> N;
    memset(grid, -1, sizeof grid);
    memset(st, false, sizeof st);
    grid[N / 2][N / 2] = 1e8;
    st[N / 2][N / 2] = true;

    for (int i = 1, x = 0, y = 0, d = 0; i < N * N; i++) {
        if (!st[x][y]) {
            grid[x][y] = i;
            st[x][y] = true;
        }
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= N || b < 0 || b >= N || st[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1e8)
                cout << "T"
                     << " ";
            else
                cout << grid[i][j] << ((j == N - 1) ? "" : " ");
        }
        cout << endl;
    }
}