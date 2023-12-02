
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

const int MAX_N = 1024;
int dp[MAX_N][MAX_N];
int N;

// 计算从（0，0） 到 （x，y） 之间的黑格子数量
LL f(int x, int y) {
    LL ret = 1LL * (x / N) * (y / N) * dp[N][N];
    ret += dp[x % N][y % N];
    ret += 1LL * dp[x % N][N] * (y / N);
    ret += 1LL * dp[N][y % N] * (x / N);
    return ret;
}

int main() {
    int Q;
    cin >> N >> Q;
    char P[MAX_N][MAX_N];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> P[i][j];
            dp[i][j] = (P[i][j] == 'B') + dp[i - 1][j] + dp[i][j - 1] -
                       dp[i - 1][j - 1];
        }
    }

    while (Q--) {
        int A, B, C, D;
        // 此时左上，右上，左下，右下 的 坐标为(A,B) , (A,D) , (C,B) , (C,D)
        cin >> A >> B >> C >> D;
        C++, D++;
        cout << f(C, D) - f(A, D) - f(C, B) + f(A, B) << endl;
    }
}