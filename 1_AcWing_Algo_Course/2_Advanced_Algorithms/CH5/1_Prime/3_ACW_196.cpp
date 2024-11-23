// Problem: https://www.acwing.com/problem/content/198/

// 质数的二次筛法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

// 筛质数（线性筛法）
void get_primes(int n) {
    memset(st, 0, sizeof st);
    cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    int l, r;
    while (cin >> l >> r) {
        get_primes(50000);

        // 找到所有[l,r]区间内，p的倍数，标记为true
        memset(st, 0, sizeof st);
        for (int i = 0; i < cnt; i++) {
            LL p = primes[i];
            // 注：(l+p-1)/p*p 作用是：找到不小于l的最小的p的倍数
            for (LL j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p)
                // 映射转换
                st[j - l] = true;
        }

        // 重新统计区间内的质数
        cnt = 0;
        for (int i = 0; i <= r - l; i++)
            if (!st[i] && i + l >= 2)
                primes[cnt++] = i + l;

        // 如果区间内质数小于 2 个，无解
        if (cnt < 2)
            cout << "There are no adjacent primes." << endl;
        else {
            int minp = 0, maxp = 0;
            for (int i = 0; i + 1 < cnt; i++) {
                int d = primes[i + 1] - primes[i];
                if (d < primes[minp + 1] - primes[minp])
                    minp = i;
                if (d > primes[maxp + 1] - primes[maxp])
                    maxp = i;
            }

            printf("%d,%d are closest, %d,%d are most distant.\n", primes[minp],
                   primes[minp + 1], primes[maxp], primes[maxp + 1]);
        }
    }
}

int main() {
    // 这题的输入比较奇葩，要把下面两句注释掉才能运行
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    solve();
    return 0;
}