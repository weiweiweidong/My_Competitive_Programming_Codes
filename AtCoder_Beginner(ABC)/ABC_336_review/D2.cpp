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
using namespace std;

const int N_MAX = 200010;
int A[N_MAX];
int A_left[N_MAX], A_right[N_MAX];
int N;

int main() {
    // 读入数据
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // 数组初始化
    memset(A_left, 0, sizeof A_left);
    memset(A_right, 0, sizeof A_right);

    // 从左往右看每个点最大能到多少
    for (int i = 1; i <= N; i++) {
        A_left[i] = min(A_left[i - 1] + 1, A[i]);
    }
    // 从右往左看每个点最大能到多少
    for (int i = N; i >= 1; i--) {
        A_right[i] = min(A_right[i + 1] + 1, A[i]);
    }

    // 开始算长度的最大值
    int res = 0;
    for (int i = 1; i <= N; i++) {
        res = max(res, min(A_left[i], A_right[i]));
    }

    // 输出
    cout << res << endl;
}