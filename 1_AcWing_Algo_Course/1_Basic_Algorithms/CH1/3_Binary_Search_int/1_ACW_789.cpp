// Problem: https://www.acwing.com/problem/content/791/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m, k;
int q[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> q[i];

    while (m--) {
        cin >> k;
        // 找左边界
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        int left = l;
        if (q[left] != k)
            left = -1;

        // 找右边界
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (q[mid] <= k)
                l = mid;
            else
                r = mid - 1;
        }
        int right = l;
        if (q[right] != k)
            right = -1;

        cout << left << " " << right << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
}