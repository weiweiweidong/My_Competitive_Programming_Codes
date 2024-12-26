# **A - Pairing**

Problem：[A - Pairing](https://atcoder.jp/contests/abc378/tasks/abc378_a)

省略。

```c++
// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int f[4];

void solve() {
    for (int i = 0; i < 4; i++) {
        int c;
        cin >> c;
        f[c]++;
    }

    int res = 0;
    for (int i = 1; i <= 4; i++)
        res += f[i] / 2;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **B - Garbage Collection**

Problem：[B - Garbage Collection](https://atcoder.jp/contests/abc378/tasks/abc378_b)

模拟题。

省略。

```c++
// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int q[N], r[N];
int n, Q;

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> q[i] >> r[i];

    cin >> Q;
    for (int i = 1, t, d; i <= Q; i++) {
        cin >> t >> d;
        int tmp = d % q[t];

        // 如果 tmp 在 r[t] 前面，说明本轮就可以扔
        if (tmp <= r[t])
            cout << d + (r[t] - tmp) << endl;
        // 否则要等到下一轮才能扔
        else
            cout << d + q[t] - tmp + r[t] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **C - Repeating**

Problem：[C - Repeating](https://atcoder.jp/contests/abc378/tasks/abc378_c)

STL

输出一个数字前面，离他最近的相同数字的位置。没有就输出 -1。

```c++
// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a;
unordered_map<int, int> q;
void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (!q.count(a))
            cout << -1 << " ";
        else
            cout << q[a] << " ";

        q[a] = i;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **D - Count Simple Paths**

Problem：[D - Count Simple Paths](https://atcoder.jp/contests/abc378/tasks/abc378_d)

DFS。

一道非常标准的 DFS 题目。

```c++
// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
string g[N];    // 存储网格
bool st[N][N];  // 存储遍历状态
int n, m, k;
int res;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int k) {
    if (k == 0) {
        res++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];

        if (a < 1 || a > n || b < 1 || b > m)
            continue;
        if (g[a][b] == '#' || st[a][b])
            continue;

        st[a][b] = true;
        dfs(a, b, k - 1);
        st[a][b] = false;
    }
}

void solve() {
    // 读入数据，1-base
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g[i] = " " + g[i];
    }

    // 对于每个点都 DFS 一遍
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '#')
                continue;

            st[i][j] = true;
            dfs(i, j, k);
            st[i][j] = false;
        }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **E - Mod Sigma Problem**

Problem：[E - Mod Sigma Problem](https://atcoder.jp/contests/abc378/tasks/abc378_e)

数论。
