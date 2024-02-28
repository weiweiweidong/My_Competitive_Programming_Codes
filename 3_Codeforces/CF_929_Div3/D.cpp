#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 找到最小值min。如果 min 只出现了一次，就是YES
    int min = *min_element(a.begin(), a.end());
    if (count(a.begin(), a.end(), min) == 1) {
        cout << "YES\n";
        return;
    }

    // 如果最小值min出现多于1次，就看数组中每个元素是否都能被最小值整除
    // 只要存在任何一个元素不能被最小值整除，就输出 YES
    for (int i = 0; i < n; i++) {
        if (a[i] % min != 0) {
            cout << "YES\n";
            return;
        }
    }

    // 否则输出 NO
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}