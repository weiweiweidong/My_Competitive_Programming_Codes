// Problem: https://www.acwing.com/problem/content/127/
// 公式推导的贪心。公式推导详见笔记
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e4 + 10;
int n;
struct Cow {
    int w, s, t;
} cow[N];

bool cmp(Cow a, Cow b) {
    return a.t < b.t;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        cow[i] = {w, s, w + s};
    }

    sort(cow, cow + n, cmp);

    // res 记录结果，sum 记录遍历完成的体重和
    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++) {
        int s = cow[i].s, w = cow[i].w;
        res = max(res, sum - s);
        sum += w;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}