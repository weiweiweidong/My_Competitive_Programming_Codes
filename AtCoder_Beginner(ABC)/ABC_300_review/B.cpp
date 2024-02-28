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
vector<vector<char>> A, B;

// 行变换
void row() {
    for (int j = 0; j < W; j++) {
        char c = A[0][j];
        for (int i = 1; i < H; i++)
            A[i - 1][j] = A[i][j];
        A[H - 1][j] = c;
    }
}
// 列变换
void col() {
    for (int i = 0; i < H; i++) {
        char c = A[i][0];
        for (int j = 1; j < W; j++)
            A[i][j - 1] = A[i][j];
        A[i][W - 1] = c;
    }
}

int main() {
    cin >> H >> W;
    A = vector<vector<char>>(H, vector<char>(W));
    B = vector<vector<char>>(H, vector<char>(W));

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> B[i][j];

    // 进行行变换
    for (int i = 0; i < H; i++) {
        // 进行列变换
        row();
        for (int j = 0; j < W; j++) {
            col();
            if (A == B) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}