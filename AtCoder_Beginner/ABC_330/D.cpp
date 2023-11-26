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

int main() {
    int N;
    cin >> N;
    vector<vector<char>> g(N, vector<char>(N));
    vector<int> row(N);  // 存储每一行有多少个 o
    vector<int> col(N);  // 存储每一列有多少个 o
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'o') {
                row[i] += (g[i][j] == 'o');
                col[j] += (g[i][j] == 'o');
            }
        }
    }

    LL res = 0;
    // 开始搜每一个格子
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] == 'o') {
                int r = row[i] - 1;
                int c = col[j] - 1;
                res += r * c;
            }
        }
    }
    cout << res << endl;
}