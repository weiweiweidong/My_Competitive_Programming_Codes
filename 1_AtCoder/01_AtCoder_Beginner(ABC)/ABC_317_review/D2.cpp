#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 110;
const int Z = 100010;
long long cost[N];
long long value[N];
long long f[N][Z];

int main() {
    int n;
    cin >> n;
    long long sum_z = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        cost[i] = max(0, (y - x + 1) / 2);
        value[i] = z;
        sum_z += z;
    }

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum_z; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= value[i])
                f[i][j] = min(f[i - 1][j], f[i - 1][j - value[i]] + cost[i]);
        }
    }

    long long res = 1e18;
    for (int i = (sum_z + 1) / 2; i <= sum_z; i++) {
        res = min(res, f[n][i]);
    }
    cout << res << endl;
}