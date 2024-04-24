// Problem: https://www.acwing.com/problem/content/5565/
// 二分

/*
    备注：这道题和 5477 基本一样，可以作为复习材料
    https://www.acwing.com/problem/content/5480/
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;  // n个物品，m个未加工零件
int a[N], b[N];

// 判断是否能生产 mid 个产品
bool check(int mid) {
    LL res = 0;
    for (int i = 0; i < n; i++) {
        LL need = (LL)mid * a[i];
        if (need > b[i]) {
            res += need - b[i];
            if (res > m)
                return false;
        }
    }
    return true;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    // 二分
    int left = 0, right = 2e9;
    while (left < right) {
        int mid = (left + (LL)right + 1) >> 1;
        if (check(mid))
            left = mid;
        else
            right = mid - 1;
    }

    cout << left << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}