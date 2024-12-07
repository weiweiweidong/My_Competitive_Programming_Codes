// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int A[N][N];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> A[i][j];

    int now = 1;
    for (int j = 1; j <= n; j++) {
        if (now >= j)
            now = A[now][j];
        else
            now = A[j][now];
    }

    cout << now << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}