#include <math.h>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

const LL MOD = 998244353, mx = 6e5 + 10;
LL s[mx], ans = 1;
int Q;
queue<LL> que;

int main() {
    s[1] = 1;
    for (int i = 2; i <= mx; i++)
        s[i] = (s[i - 1] * 10) % MOD;
    que.push(1);

    cin >> Q;
    while (Q--) {
        LL op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            que.push(x);
            ans = (ans * 10 + x) % MOD;
        } else if (op == 2) {
            x = que.front();
            ans = (ans - x * s[que.size()] + MOD * 10) % MOD;
            que.pop();
        } else {
            cout << ans << endl;
        }
    }
}