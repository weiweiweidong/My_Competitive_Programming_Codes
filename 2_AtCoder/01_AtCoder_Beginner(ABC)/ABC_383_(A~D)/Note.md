---
title: ABC 383 Summary
date: 2024-12-08 10:02:12
tags:
  - Algorithm
  - Prgoramming Contest
  - ABC
mathjax: true
---

# A

构造题。

省略。



# B

Problem：[B - Humidifier 2](https://atcoder.jp/contests/abc383/tasks/abc383_b)

暴力搜索。

由于数据范围非常小，网格最大也才 $10\times 10$，所以直接暴力枚举两个加湿器的位置，然后暴力计算每个点和加湿器的位置即可。

```c++
// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
char g[N][N];
bool st[N][N];
int res;
int h, w, d;

int check(int a, int b, int x, int y) {
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (g[i][j] == '.')
                if (abs(i - a) + abs(j - b) <= d ||
                    abs(i - x) + abs(j - y) <= d) {
                    ans++;
                }

    return ans;
}

void solve() {
    cin >> h >> w >> d;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> g[i][j];

    // 确定第一台的位置
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            // 确定第二台的位置
            for (int x = 0; x < h; x++)
                for (int y = 0; y < w; y++) {
                    // 如果是同一个点，跳过
                    if (i == x && j == y)
                        continue;
                    // 如果两个点都是 地板
                    if (g[i][j] == '.' && g[x][y] == '.') {
                        res = max(res, check(i, j, x, y));
                    }
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
```



# C

Problem：[C - Humidifier 3](https://atcoder.jp/contests/abc383/tasks/abc383_c)

图论题目。

题目本质是在问每个格子到最近的 H 距离是多少。使用经典的“虚拟节点”方法转换为单源最短路问题。

```c++
// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, M = 20 * N;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int st[N];

int H, W, d;
char g[1010][1010];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

// SPFA 算法
void spfa() {
    int start = 1e6 + 5;
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    st[start] = true;

    while (q.size()) {
        int now = q.front();
        q.pop();
        st[now] = false;

        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (dist[next] > dist[now] + w[i]) {
                dist[next] = dist[now] + w[i];
                if (!st[next]) {
                    q.push(next);
                    st[next] = true;
                }
            }
        }
    }
}

void solve() {
    // 读入网格数据
    cin >> H >> W >> d;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> g[i][j];

    // 建图
    memset(h, -1, sizeof h);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            // ‘#’点不建图
            if (g[i][j] == '#')
                continue;
            int now = i * W + j;
            // ‘H’点额外添加和虚拟节点 1e6+5 的 0 边权的边
            if (g[i][j] == 'H') {
                add(1e6 + 5, now, 0), add(now, 1e6 + 5, 0);
            }
            // 看一下周围四个点能不能建边
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k], b = j + dy[k];
                // 越界
                if (a < 0 || a >= H || b < 0 || b >= W)
                    continue;
                // 遇到 #
                if (g[a][b] == '#')
                    continue;
                // 建边
                add(now, a * W + b, 1);
            }
        }

    spfa();

    // 遍历，看距离 H 在 d 以内的点有多少
    int res = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (g[i][j] != '#' && dist[i * W + j] <= d)
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



# D

Problem：[D - 9 Divisors](https://atcoder.jp/contests/abc383/tasks/abc383_d)

数论题目。

能满足只有 9 个约数的数字实际上不多。

> 约数基本定理：
>
> ​	一个数能被拆成若干个质数乘积的形式 $N=P_{1}^{a_1}P_{2}^{a_2}\dots P_{k}^{a_k}$，那么 N 的约数个数为 $(a_1+1)(a_2+1)\dots (a_k+1)$。

按照上面的格式，9 只能被拆分为 $1\times9$ 或者 $3\times 3$ 两种可能性。

	- $1\times9$ ：表明数字 $N = P^8$，是某一个质数的 8 次方
	- $3\times 3$ ：表示数字 $N = P_i^2 \times P_j^2$，是某两个质数的平方和

思路：

​	预处理出来质数表。分成两种情况遍历即可。这道题也并不需要真的预处理出来 $4\times 10^{12}$ 这么多数字，只需要计算到 $\sqrt{4\times 10^{12}} = 2 \times 10^6$ 即可。 

```c++
// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL N = 2e6 + 10;
LL primes[N], cnt;
bool st[N];
LL n;

// 线性筛法模板
void get_primes(LL x) {
    for (LL i = 2; i <= x; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (LL j = 0; primes[j] * i <= x; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

// 计算 x^4 的值
LL pow_4(LL x) {
    return x * x * x * x;
}

void solve() {
    // 读入数据，计算平方根
    cin >> n;
    LL intSqrt = sqrt(n) + 1;

    // 预处理质数表
    get_primes(intSqrt);

    // 讨论 1*8 的情况
    int res = 0;
    for (int i = 0; i < cnt; i++) {
        if (pow_4(primes[i]) < intSqrt)
            res++;
        // 防止溢出，超出界限直接 break，后面的再不算了
        else
            break;
    }

    // 讨论 3*3 的情况
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++) {
            LL temp = primes[i] * primes[j];
            if (temp < intSqrt)
                res++;
            // 防止溢出，超出界限直接 break
            else
                break;
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

# E

Problem：[E - Sum of Max Matching](https://atcoder.jp/contests/abc383/tasks/abc383_e)

