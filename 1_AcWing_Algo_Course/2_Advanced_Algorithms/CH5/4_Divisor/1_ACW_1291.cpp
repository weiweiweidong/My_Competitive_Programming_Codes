// Problem: https://www.acwing.com/problem/content/1293/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 1e6 + 10;
int n;
int a[N];
int cnt[M];  // 统计每个数字出现的次数
int s[M];    // 存储每个数的约数出现次数之和
int max_a;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;  // 统计每个数字出现的次数
        max_a = max(max_a, a[i]);
    }

    // 看上去是 n^2 的时间复杂度，但实际上是 nlogn
    for (int i = 1; i <= max_a; i++)         // 枚举每个可能的数
        for (int j = i; j <= max_a; j += i)  // 枚举 i 的倍数：j
            // 由于j的约数中包含i，加上i出现的次数
            s[j] += cnt[i];

    for (int i = 0; i < n; i++)
        // 把自己给减掉
        cout << s[a[i]] - 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}