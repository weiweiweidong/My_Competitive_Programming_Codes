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
using namespace std;

typedef long L;
typedef long long LL;
typedef pair<int, int> PII;

const int N_MAX = 2e6 + 10;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> grid(N_MAX, vector<int>(2, 0));

    for (int i = 1; i <= N; i++) {
        grid[N + 1 - i] = {i, 0};
    }

    int hh = N, tt = 1;

    while (Q--) {
        int q;
        cin >> q;
        // 如果是移动指示
        if (q == 1) {
            string C;
            cin >> C;
            auto t = grid[hh];
            hh++;
            if (C == "R") {
                grid[hh] = {t[0] + 1, t[1]};
            } else if (C == "L") {
                grid[hh] = {t[0] - 1, t[1]};
            } else if (C == "U") {
                grid[hh] = {t[0], t[1] + 1};
            } else {
                grid[hh] = {t[0], t[1] - 1};
            }
            tt++;
        }
        // 如果是查询指示
        else {
            int c;
            cin >> c;
            cout << grid[hh - c + 1][0] << " " << grid[hh - c + 1][1] << endl;
        }
    }
}