// Problem: https://atcoder.jp/contests/abc386/tasks/abc386_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[4];
map<int, int> h;

void solve() {
    // 读入四个数，同时计数
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
        h[a[i]]++;
    }

    // 排序一下
    sort(a, a + 4);

    // 我们只看第一个数和最后一个数即可
    // 只能是 22 或者 13 或者 31 的形式，才能构成题目需要的形式
    if ((h[a[0]] == 2 && h[a[3]] == 2) || (h[a[0]] == 3 && h[a[3]] == 1) ||
        (h[a[0]] == 1 && h[a[3]] == 3))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}