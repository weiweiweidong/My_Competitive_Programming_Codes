// Problem: https://www.acwing.com/problem/content/803/
// 使用 lowbit，计算二进制中有多少个1
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N];
int n;

int lowbit(int x) {
    return x & -x;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int res = 0;
        int x = a[i];
        while (x) {
            res++;
            x -= lowbit(x);
        }
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}