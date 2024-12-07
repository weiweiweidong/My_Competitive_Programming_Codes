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

typedef long L;
typedef long long LL;
using namespace std;

// 矩阵顺时针旋转90度
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 转置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 轴对称
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }
}

// 判断是否满足条件
bool check(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> B(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    for (int i = 0; i < 4; i++) {
        if (check(A, B)) {
            cout << "Yes" << endl;
            return 0;
        }
        rotate(A);
    }

    cout << "No" << endl;
    return 0;
}