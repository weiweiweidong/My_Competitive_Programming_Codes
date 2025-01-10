# **A - Happy New Year 2025**

Problem：[A - Happy New Year 2025](https://atcoder.jp/contests/abc387/tasks/abc387_a)

计算 A+B 的平方。签到题。

```c++
// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a, b;

void solve() {
    cin >> a >> b;
    cout << (a + b) * (a + b) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **B - 9x9 Sum**

Problem：[B - 9x9 Sum](https://atcoder.jp/contests/abc387/tasks/abc387_b)

判断 x 是否在 99 乘法表中出现，并计算乘法表剩余的数字的总和。签到题。

```c++
// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int x;

void solve() {
    cin >> x;

    LL res = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (i * j != x)
                res += 1ll * i * j;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

# **C - Snake Numbers**

Problem：[C - Snake Numbers](https://atcoder.jp/contests/abc387/tasks/abc387_c)

## 题目：

10 以上的十进制正整数，最高位比剩下所有位数的值都严格大的数字称为“蛇数”。例如 `31` 和  `201` 是蛇数，但是 `35`  `202` 不是蛇数。

求 L 到 R 之间有多少个蛇数。

## 约束条件：

$10 \leq L \leq R \leq 10^{18}$

## 思路：

### 方法 1：计数

关键在于最高位。决定了最高位，就相当于决定了剩下每一位的上限。

为了应对 <= R 的限制，可以考虑枚举数字的长度。假设数字的长度为 len，R 的长度为 R_len

第一种情况：如果 len < R_len，说明不管当前数字怎么取，肯定都是小于 R 的。假设最高位选为 t，那么就一共有 t^{len -1 } 个蛇形数。

第二种情况：如果 len == R_len

​	子情况 1：最高位 t == R 的最高位。枚举我们构造的蛇形数与 R 的第一个不同的位数在哪里。假设是第 i 位，那么第 i 位以后的数字就可以随便填了。一共有 t^(len- i) 种可能

​	子情况 2：最高位 t != R 的最高位。那么还是有 t^(len-1) 种

```c++
// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL L, R;

LL fpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

// 统计 [1,lx] 之间的蛇形数的个数
LL cal(LL lx) {
    if (lx < 10)
        return 0;

    LL num = 0;
    string x = to_string(lx);
    int high = x[0] - '0';
    LL len = x.size();

    // 情况 1：
    for (int i = 2; i < len; i++)     // 枚举长度
        for (int j = 1; j <= 9; j++)  // 枚举首位
            num += fpow(j, i - 1);

    // 处理相同位数，但是首位更小的情况
    for (int j = 1; j < high; j++)
        num += fpow(j, len - 1);

    // 处理首位相同的情况：从高向低挨个看
    for (int j = 0; j < len; j++) {
        // 如果某一位大于等于high，无论后面是什么数字，都不可能构成蛇形数了
        if (j != 0 && int(x[j] - '0') >= high)
            break;

        // 只看中间的位置
        if (j < len - 1) {
            // 下一位可以取的数就是 min(当前位数字, high)
            num += min(int(x[j + 1] - '0'), high) * fpow(high, len - j - 2);
        }

        // 处理最后一位：如果能处理到最后一位了，说明x本身就是个蛇形数，把自己加上
        if (j == len - 1)
            num += 1;
    }

    return num;
}

void solve() {
    cin >> L >> R;
    cout << cal(R) - cal(L - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```



### 方法 2：数位 DP





# **D - Snaky Walk**

Problem：[D - Snaky Walk](https://atcoder.jp/contests/abc387/tasks/abc387_d)

## 题目：

给定一个 H*W 的网格。

`S` 为起点，`G` 为终点，`#` 为障碍物，`.` 为可以行走的格子。

可以四方向行走。但是要求为：如果前一次为水平移动，下一次要上下移动；如果前一次为上下移动，下一次要水平移动。

求从 `S` 移动到 `G` 的最短距离。如果不能走到，输出 `-1`

示例：

<img src="./assets/image-20250105184444497.png" alt="image-20250105184444497" style="zoom:67%;" />

## 约束条件：

$1 \leq H,W \leq 1000$

## 思路：

本题求最短距离显然使用 BFS。

但是由于对移动方向有限制，使用 BFS 的时候需要多开一个维度来记录来时的方向。

```c++
// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

char g[N][N];      // 存储网格
bool st[N][N][2];  // 存储每个点的遍历状态
int dis[N][N][2];  // 存储每个点的距离
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};  // 按照 左右上下 的方向
struct Node {
    int x, y, d;
};
int n, m;

// 判断当前点是否合法
bool check(int x, int y, int d) {
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    if (g[x][y] == '#' || st[x][y][d])
        return false;
    return true;
}

void solve() {
    // 读入数据，保存起始点
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S')
                x = i, y = j;
        }

    // 队列初始化
    queue<Node> q;
    q.push({x, y, 0});
    q.push({x, y, 1});
    st[x][y][0] = st[x][y][1] = true;

    // BFS
    while (q.size()) {
        Node now = q.front();
        q.pop();
        int x = now.x, y = now.y, d = now.d;

        // 如果遇到终点，就输出（第一次遇到终点也就是距离最短的时候）
        if (g[x][y] == 'G') {
            cout << dis[x][y][d] << endl;
            return;
        }

        // 遍历下个方向
        for (int i = 2 * d; i < 2 + 2 * d; i++) {
            // d=0时，i=0 1，向左右走 ； d=1时，i= 2 3，向上下走
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny, !d)) {
                q.push({nx, ny, !d});
                dis[nx][ny][!d] = dis[x][y][d] + 1;
                st[nx][ny][!d] = true;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
```

