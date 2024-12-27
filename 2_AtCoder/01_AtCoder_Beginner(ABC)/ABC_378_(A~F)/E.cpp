// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n, m;
int a[N];   // 储存原数组
int s[N];   // 储存：带模前缀和
int tr[N];  // BIT

int lowbit(int x) {
    return x & -x;
}

// 更新 BIT 的值
void add(int x, int k) {
    x++;
    for (int i = x; i <= N; i += lowbit(i))
        tr[i] += k;
}

// 求前x个数的数量和
int sum(int x) {
    x++;
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // 预处理带模前缀和
        s[i] = (s[i - 1] + a[i]) % m;
    }

    LL res = 0;
    // 计算公式的第一部分
    for (int r = 1; r <= n; r++)
        res += 1ll * s[r] * r;
    // 计算公式的第二部分
    for (int l = 1; l <= n; l++)
        res -= 1ll * s[l - 1] * (n - l + 1);

    // 计算逆序对
    LL cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (i - 1 - sum(s[i]));
        add(s[i], 1);
    }
    // 计算公式第三部分
    res += 1ll * m * cnt;

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}