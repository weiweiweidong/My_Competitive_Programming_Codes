// Problem: https://atcoder.jp/contests/abc381/tasks/abc381_d

// 双指针 / 滑动窗口
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int A[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int res = 0;
    unordered_map<int, int> h;
    for (int left = 0, right = 0; left < n - 1; left++) {
        // 如果出现连续三个以上的相同字符，落到最后一对相同字符上面
        while (left + 2 < n && A[left] == A[left + 1] &&
               A[left + 1] == A[left + 2])
            left++;

        // 如果left 和 left+1 字符相同
        if (A[left] == A[left + 1]) {
            // 就向右继续搜
            if (right < left || (right - left) % 2) {
                right = left;
                h.clear();
            }

            // 约束条件：1. 不越界 2. 前后相同 3. 没出现过
            while (right + 1 < n && A[right] == A[right + 1] && !h[A[right]]) {
                h[A[right]] = 2;
                // right 向右跳两格
                right += 2;
            }

            res = max(res, right - left);

            // left 向右跳
            left++;
            h[A[left]] = 0;
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}