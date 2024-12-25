# **A - Equally**

Problem：[A - Equally](https://atcoder.jp/contests/abc385/tasks/abc385_a)

有两种思路。

	1. 分成四种情况来讨论
	1. 只要 abc 的总和能被 abc 中的最大值整除，就意味着能被分开。（很巧妙）

```c++
// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;

// 解法 1：分成四种情况来讨论
void solve1() {
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a || (a == b && b == c))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

// 解法 2：只要 sum 能被 abc 中的最大值整除即可
void solve2() {
    cin >> a >> b >> c;
    int mx = max({a, b, c});
    int sum = a + b + c;
    if (sum % mx == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve1();
    // solve2();
    return 0;
}
```

# **B - Santa Claus 1**

Problem：[B - Santa Claus 1](https://atcoder.jp/contests/abc385/tasks/abc385_b)

模拟题。

省略。

```c++
// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
char g[N][N];
int h, w, x, y;
string s;
bool st[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int res;

// 转换函数：把 UDLR 转换为 idx
int trans(char c) {
    if (c == 'U')
        return 0;
    else if (c == 'D')
        return 1;
    else if (c == 'L')
        return 2;
    else
        return 3;
}

void solve() {
    // 读入数据
    cin >> h >> w >> x >> y;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> g[i][j];
    cin >> s;
    // 1-base 转换为 0-base
    x--, y--;
    // 遍历每个指令
    for (auto c : s) {
        int d = trans(c);
        // 计算下一个点的坐标
        int a = x + dx[d], b = y + dy[d];
        // 越界
        if (a < 0 || a >= h || b < 0 || b >= w)
            continue;
        // 撞墙
        if (g[a][b] == '#')
            continue;
        // 如果是第一次遇见'@'，计数+1
        if (g[a][b] == '@' && !st[a][b]) {
            st[a][b] = true;
            res++;
        }
        // 更新坐标
        x = a, y = b;
    }

    // 输出结果
    cout << x + 1 << " " << y + 1 << " " << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **C - Illuminate Buildings**

Problem：[C - Illuminate Buildings](https://atcoder.jp/contests/abc385/tasks/abc385_c)

DP

## 题目：

N 栋建筑排成一列。高度为 H_i

想要给建筑点灯，有下面要求：

- 选中的建筑物要有相同的高度
- 选中建筑物之间间隔相同

求能选出的最多建筑。

## 约束条件：

$1 \leq N \leq 3000$
$1 \leq H_i \leq 3000$

## 思路：

DP 的最长子序列问题。

令 `f[i][j]` 表示：以第 `i` 个位置结尾，且前后两个相同数字的距离是 `j` 时，最大长度。

时间复杂度为 $O(n^2)$，本题中为 $3000^2 = 9,000,000 $ 的时间复杂度。

```c++
// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_c

// DP
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3010;
int a[N];
int f[N][N];
int n, res;

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // dp 数组初始化
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 1;

    // f[i][j] 表示：以第i个位置结尾，且前后两个相同数字距离是j时，最大长度
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i - j >= 1 && a[i] == a[i - j])
                f[i][j] = max(f[i][j], f[i - j][j] + 1);
            res = max(res, f[i][j]);
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

# **D - Santa Claus 2**

Problem：[D - Santa Claus 2](https://atcoder.jp/contests/abc385/tasks/abc385_d)

STL + 二分

## 题目：

二维平面上有坐标为 $(X_1,Y_1), ... ,(X_N,Y_N)$ 共 $N$ 个房子。

最开始，圣诞老人在起点 $(S_x,S_y)$ 处，按照序列 $(D_1,C_1), ... ,(D_M,C_M)$ 方式移动

- 若 $(x,y)$ 是当前点坐标
  - 若 $D_i$ 是 `U`，则沿着直线从 $(x,y)$ 移动到 $(x, y+C_i)$
  - 若 $D_i$ 是 `D`，则沿着直线从 $(x,y)$ 移动到 $(x, y-C_i)$
  - 若 $D_i$ 是 `L`，则沿着直线从 $(x,y)$ 移动到 $(x-C_i, y)$
  - 若 $D_i$ 是 `R`，则沿着直线从 $(x,y)$ 移动到 $(x+C_i, y)$

求出完成所有移动后，圣诞老人经过的房子的数量。（若多次经过相同房间，只计算 1 次）

## 约束条件：

$1 \leq N \leq 2\times 10^5$

$1 \leq M \leq 2\times 10^5$

$-10^9 \leq X_i,Y_i \leq 10^9$

There is no house at $(S_x,S_y)$.

$1 \leq C_i \leq 10^9$

## 思路：

有两个核心问题：

1. 如何快速知道一次移动中会经过多少个房子
2. 如何筛选掉已经走过的房子

容易发现，每次的移动都是直上直下或者水平的移动，也就是说在移动的时候，其中一个坐标轴的坐标是固定的。

解决方法：

- 维护一个特殊的数据结构：`map<int , set<int>>`，再使用二分。

举例：对于数据结构 `map<int , set<int>> mx` 来说，key 存储的是每个房子的 x 坐标，value 存的是相同 x 坐标的所有 y 坐标的值。那么在一次移动中，一定会对应左右端点。那么使用二分在 set 中查找左右端点，中间的值就是经过的点。将这几个点从 set 中清除掉，就实现了只计算一次经过的功能。

时间复杂度为 $O(m*2\log n)$，对应的是 m 次移动，每次移动中会进行两次二分查找。

```c++
// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

using Map = map<int, set<int>>;

Map mx, my;
vector<int> temp;
int n, m;  // 点的数量，移动次数
LL x, y;   // 起始坐标
LL res;
char d;  // 临时变量，记录移动方向
LL c;    // 临时变量，记录移动距离

//
void run(LL x, LL y, LL u, LL v, Map& i, Map& j) {
    // 判断点的位置是否合法
    if (!(!i[x].empty() && fabs(x) <= 1e9 && fabs(y) <= 1e9))
        return;

    temp.clear();

    auto bg = i[x].lower_bound(y + u);
    auto ed = i[x].upper_bound(y + v);

    // 从 bg 到 ed 之间所有的元素都要删除并计数
    for (auto it = bg; it != ed; it++) {
        res++;
        temp.push_back((*it));
    }

    // 在原始数组中删除经过的点
    for (auto p : temp) {
        i[x].erase(p);
        j[p].erase(x);
    }
}

void solve() {
    // 读入数据
    cin >> n >> m >> x >> y;
    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        mx[u].insert(v);  // x 下有多少个 y
        my[v].insert(u);  // y 下有多少个 x
    }
    // 处理所有移动
    for (int i = 1; i <= m; i++) {
        char d;
        cin >> d >> c;  // 读入移动方向和距离

        if (d == 'U')
            run(x, y, 0, c, mx, my), y += c;
        if (d == 'D')
            run(x, y, -c, 0, mx, my), y -= c;
        if (d == 'L')
            run(y, x, -c, 0, my, mx), x -= c;
        if (d == 'R')
            run(y, x, 0, c, my, mx), x += c;
    }

    cout << x << " " << y << " " << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

