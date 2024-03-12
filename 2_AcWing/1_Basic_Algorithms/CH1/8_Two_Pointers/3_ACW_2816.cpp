// Problem: https://www.acwing.com/problem/content/2818/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j])
            i++;
        j++;
    }
    if (i == n)
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