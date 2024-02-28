#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

int main() {
    vector<vector<int> > grid(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }

    // 扫各个行
    for (int i = 0; i < 9; i++) {
        set<int> h;
        for (int j = 0; j < 9; j++) {
            h.insert(grid[i][j]);
        }
        if (h.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 扫各个列
    for (int j = 0; j < 9; j++) {
        set<int> h;
        for (int i = 0; i < 9; i++) {
            h.insert(grid[i][j]);
        }
        if (h.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 扫各个square
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            set<int> h;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    h.insert(grid[m * 3 + i][n * 3 + j]);
                }
            }
            if (h.size() != 9) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}