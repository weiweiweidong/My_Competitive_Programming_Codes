#include <math.h>
#include <string.h>
#include <algorithm>
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
const int MAX_N = 20;
LL graph[MAX_N][MAX_N];
bool st[MAX_N];
int N;
LL res;
LL path;

void dfs(int pos, bool can_skip) {
    if (pos > N) {
        res = max(res, path);
        return;
    }

    if (st[pos]) {
        dfs(pos + 1, can_skip);
        return;
    }

    if (can_skip) {
        dfs(pos + 1, 0);
    }

    for (int i = pos + 1; i <= N; i++) {
        if (!st[i]) {
            st[i] = true;
            path += graph[pos][i];
            dfs(pos + 1, can_skip);
            path -= graph[pos][i];
            st[i] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            LL x;
            cin >> x;
            graph[i][j] = graph[j][i] = x;
        }
    }
    memset(st, false, sizeof st);

    dfs(1, N % 2);

    cout << res << endl;
}