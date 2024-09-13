// Problem: https://atcoder.jp/contests/abc369/tasks/abc369_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 最暴力解法，不推荐
void solve() {
    int A, B;
    cin >> A >> B;
    if (A >= B)
        swap(A, B);
    int res = 0;

    for (int i = -210; i <= 210; i++) {
        if (A - i == B - A || i - A == B - i || B - A == i - B)
            res++;
    }
    cout << res << endl;
}

void solve2() {
    int A, B;
    cin >> A >> B;
    if (A > B)
        swap(A, B);

    set<int> S;
    // 看一下中点是否存在
    if ((A + B) % 2 == 0)
        S.insert((A + B) >> 1);
    // 再把左右两个点加进来
    S.insert(B + B - A), S.insert(A - (B - A));

    cout << S.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // solve();
    solve2();
    return 0;
}