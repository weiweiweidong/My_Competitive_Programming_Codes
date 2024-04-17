#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int A[3][3];
int grid[3][3];  // 0 = empty, 1 = Takahashi, 2 = Aoki

bool check_win(int player) {
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == player && grid[i][1] == player &&
            grid[i][2] == player)
            return true;
        if (grid[0][i] == player && grid[1][i] == player &&
            grid[2][i] == player)
            return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;
    return false;
}

// Minimax algorithm with depth
int minimax(int depth, bool isMaximizingPlayer) {
    int bestScore = (isMaximizingPlayer ? INT_MIN : INT_MAX);

    if (check_win(1))
        return 1;  // Takahashi win
    if (check_win(2))
        return -1;  // Aoki win

    // Draw or full grid condition
    bool full = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] == 0)
                full = false;

    if (full)
        return 0;  // Draw or compare scores condition

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 0) {
                grid[i][j] =
                    (isMaximizingPlayer ? 1 : 2);  // Make the move for player
                int score = minimax(depth + 1, !isMaximizingPlayer);
                grid[i][j] = 0;  // Undo the move
                bestScore = (isMaximizingPlayer ? max(score, bestScore)
                                                : min(score, bestScore));
            }
        }
    }
    return bestScore;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }

    memset(grid, 0, sizeof(grid));  // Reset the grid
    int result = minimax(0, true);  // Start with Takahashi
    if (result == 1)
        cout << "Takahashi";
    else if (result == -1)
        cout << "Aoki";
    else
        cout << "Draw";

    return 0;
}
