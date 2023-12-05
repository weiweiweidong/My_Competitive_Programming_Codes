#include <math.h>
#include <string.h>
#include <algorithm>
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

const int MAX_N = 200010;
vector<vector<int>> edge[MAX_N];
bool decidable[MAX_N];
LL res[MAX_N][2];

void dfs(int id, LL x, LL y) {
    if (decidable[id])
        return;
    decidable[id] = true;
    res[id][0] = x;
    res[id][1] = y;

    for (auto& vi : edge[id]) {
        dfs(vi[0], x + vi[1], y + vi[2]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int A, B, X, Y;
        cin >> A >> B >> X >> Y;
        edge[A].push_back({B, X, Y});
        edge[B].push_back({A, -X, -Y});
    }

    dfs(1, 0, 0);

    for (int i = 1; i <= N; i++) {
        if (decidable[i])
            cout << res[i][0] << " " << res[i][1] << endl;
        else
            cout << "undecidable" << endl;
    }
}
