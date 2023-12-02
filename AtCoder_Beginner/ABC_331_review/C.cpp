
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

int main() {
    LL N;
    cin >> N;
    // 存储原始数列 A
    vector<LL> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    // f 用于排序
    vector<LL> f = A;
    sort(f.begin(), f.end());
    // sum 用于求前缀和
    vector<LL> sum(N + 1);
    for (int i = 1; i <= N; i++)
        sum[i] = sum[i - 1] + (LL)f[i];

    // 开始遍历每一位
    for (int i = 1; i <= N; i++) {
        LL x = A[i];
        // 二分查找大于 x 的第一个数的位置
        int pos = upper_bound(f.begin(), f.end(), x) - f.begin();
        // 如果超出范围了，输出 0
        if (pos == N + 1)
            cout << "0"
                 << " ";
        // 否则输出前缀和
        else
            cout << sum[N] - sum[pos - 1] << " ";
    }
    cout << endl;
}