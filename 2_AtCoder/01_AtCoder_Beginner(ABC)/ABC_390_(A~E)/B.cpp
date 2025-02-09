// Problem: https://atcoder.jp/contests/abc390/tasks/abc390_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n;
LL a[N];

void solve() {
    // 读入所有数据
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool flag = true;

    // 如果数列包含三个以上的数字，为了避免除法出现小数，只需要满足下面条件即可：
    // 条件：a_{i+1}^2 == a_{i}*a_{i+2}
    // 注意： 1<= a_i <= 10^9，为了避免相乘后溢出，需要使用 LL
    if (n >= 3) {
        for (int i = 0; i < n - 2; i++) {
            if (a[i + 1] * a[i + 1] != a[i] * a[i + 2])
                flag = false;
        }
    }

    if (flag)
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