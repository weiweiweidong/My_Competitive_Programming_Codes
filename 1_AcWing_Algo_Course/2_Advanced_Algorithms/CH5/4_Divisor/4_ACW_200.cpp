// Problem: https://www.acwing.com/problem/content/202/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 50010;

int primes[N], cnt;  // primes数组存储质数，cnt记录质数个数
bool st[N];          // st数组用于标记数是否被筛掉
// Factor 存储质因子。p表示质数，s表示这个质数的次数
struct Factor {
    int p, s;
} factor[10];
int fcnt;  // 记录质因子的个数

int dividor[1601], dcnt;  // dividor数组存储所有约数，dcnt记录约数个数

int T;

// 线性筛法预处理出所有的质数
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

// u 为要看的质数index，p 为当前的约数值
void dfs(int u, int p) {
    // 如果处理完所有的质因子，就把得到的数存入数组
    if (u == fcnt) {
        dividor[dcnt++] = p;
        return;
    }

    // 枚举质因子可能的次数（0到s次）
    for (int i = 0; i <= factor[u].s; i++) {
        dfs(u + 1, p);     // 递归处理下一个质因子
        p *= factor[u].p;  // 将当前约数乘以当前质因子
    }
}

// 求 a 和 b 的最大公约数
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    // 预处理出所有的质数
    get_primes(N - 1);

    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // 分解出 d 的所有质因数
        fcnt = 0;
        int t = d;
        // 优化：只需要检查到 √t 即可。
        // 如果有一个数x>√t是t的质因数，那么一定对应一个y<√t，而y在前面已经被试过了
        for (int i = 0; primes[i] <= t / primes[i]; i++) {
            int p = primes[i];
            if (t % p == 0) {
                int s = 0;
                while (t % p == 0)
                    t /= p, s++;
                factor[fcnt++] = {p, s};  // 记录质因数及次数
            }
        }

        if (t > 1)  // 处理最后可能剩下的质数
            factor[fcnt++] = {t, 1};

        // 求 d 的所有约数
        dcnt = 0;
        dfs(0, 1);

        // 枚举所有的约数，看是否满足条件
        int res = 0;
        for (int i = 0; i < dcnt; i++) {
            int x = dividor[i];  // 取出约数
            /*
            如果：
                1. a和x的最大公约数为b
                2. c和x的最小公倍数为d
            */
            if (gcd(a, x) == b && (LL)c * x / gcd(c, x) == d)
                res++;
        }

        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}