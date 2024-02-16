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

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (string& x : grid)
        cin >> x;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (grid[i][j] == 'T' && grid[i][j + 1] == 'T') {
                grid[i][j] = 'P', grid[i][j + 1] = 'C';
            }
        }
    }

    for (string& x : grid) {
        cout << x << endl;
    }
}