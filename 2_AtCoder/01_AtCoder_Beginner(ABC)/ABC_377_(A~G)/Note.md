# **A - Rearranging ABC**

Problem：[A - Rearranging ABC](https://atcoder.jp/contests/abc377/tasks/abc377_a)

省略。

```c++
// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;

void solve() {
    cin >> s;
    sort(s.begin(), s.end());
    if (s == "ABC")
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
```

# **B - Avoid Rook Attack**

Problem：[B - Avoid Rook Attack](https://atcoder.jp/contests/abc377/tasks/abc377_b)

省略。

```c++
// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10;
char g[N][N];
int col[N], row[N];  // 记录该行该列是否被占用

void solve() {
    // 读入网格数据
    for (int i = 0; i < 8; i++)
        cin >> g[i];

    // 记录行列占用情况
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (g[i][j] == '#')
                col[j] = row[i] = 1;

    // 判断每个点是否安全
    int res = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (!row[i] && !col[j])
                res++;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **C - Avoid Knight Attack**

Problem：[C - Avoid Knight Attack](https://atcoder.jp/contests/abc377/tasks/abc377_c)

STL

## 题目：

一个 N*N 的网格。骑士可以按照下面形式攻击周围的 8 个格子。

<img src="./assets/871985d4de26cef302c00cdd6f178880.png" alt="img" style="zoom: 50%;" />

输出网格上有多少安全点。

## 约束条件：

$1\leq N\leq10^9$

$1\leq M\leq2\times10^5$

$1\leq a_k\leq N,1\leq b_k\leq N\ (1\leq k\leq M)$

$(a_k,b_k)\neq(a_l,b_l)\ (1\leq k\lt l\leq M)$

## 思路：

题目的关键在于如何“去重”。

### 方法 1：（稍微麻烦一些）

使用 `unordered_map<int, unordered_set<int> >`，其中，第一维度用来存储 x 坐标，第二维度用于存储 y 坐标，`unordered_set` 就会自动对 y 的坐标进行去重。

```c++
// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int a[N], b[N];  // 存储棋子的放置位置
unordered_map<int, unordered_set<int> > occupation;

bool check(int x, int y) {
    // 如果超出范围
    if (x < 1 || x > N || y < 1 || y > N)
        return false;
    return true;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        // 将棋子的位置标记为已占用
        occupation[a[i]].insert(b[i]);
    }

    // 存储每一个棋子的攻击范围
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 8; j++) {
            int next_a = a[i] + dx[j];
            int next_b = b[i] + dy[j];
            if (check(next_a, next_b)) {
                occupation[next_a].insert(next_b);
            }
        }
    }

    // 开始计算总共被占用了多少位置
    LL oc = 0;
    for (auto [x, y] : occupation)
        oc += (LL)y.size();

    // 计算剩下了多少位置
    cout << (LL)n * n - oc << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

### 方法 2：（好写一些）

`set<pair<int,int>>` 可以自动对整数对去重。但是 `unordered_set<pair<int,int>>`  不行。

```c++
// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int a[N], b[N];  // 存储棋子的放置位置
set<PII> occupation;

bool check(int x, int y) {
    // 如果超出范围
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        // 将棋子的位置标记为已占用
        occupation.insert({a[i], b[i]});
    }

    // 存储每一个棋子的攻击范围
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 8; j++) {
            int next_a = a[i] + dx[j];
            int next_b = b[i] + dy[j];
            if (check(next_a, next_b))
                occupation.insert({next_a, next_b});
        }
    }

    // 计算剩下了多少位置
    LL res = (LL)n * n - occupation.size();
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **D - Many Segments 2**

Problem：[D - Many Segments 2](https://atcoder.jp/contests/abc377/tasks/abc377_d)

## 题目：

给定长度为 $N$ 的两个正整数数列 $(A_1, A_2, ..., A_N)$ 和 $(B_1, B_2, ..., B_N)$ 

给定正整数 $M$

求出满足下面条件的整数对 $(l,r)$ 的个数。

- $1\le l \le r \le M$
- 区间 $[l,r]$ 不会完整的包含区间 $[L_i,R_i]$

## 约束条件：

$1\le N,M\le 2\times 10^5$

$1\le L_i\le R_i\le M$

## 思路：

