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

int main() {
    int N;
    cin >> N;
    vector<vector<bool>> grid(120, vector<bool>(120, false));

    while (N--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        // x 范围
        for (int i = A; i < B; i++) {
            // y 范围
            for (int j = C; j < D; j++)
                grid[i][j] = true;
        }
    }

    // 计算面积
    int res = 0;
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 120; j++) {
            if (grid[i][j])
                res++;
        }
    }

    cout << res << endl;
}