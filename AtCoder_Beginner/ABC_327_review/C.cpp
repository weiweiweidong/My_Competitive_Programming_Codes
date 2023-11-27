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
    vector<vector<int>> A(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> A[i][j];

    // 看所有行
    for (int i = 0; i < 9; i++) {
        unordered_set<int> s;
        for (int j = 0; j < 9; j++)
            s.insert(A[i][j]);
        if (s.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 看所有列
    for (int j = 0; j < 9; j++) {
        unordered_set<int> s;
        for (int i = 0; i < 9; i++)
            s.insert(A[i][j]);
        if (s.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 看所有小方格
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            unordered_set<int> s;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    s.insert(A[3 * m + i][3 * n + j]);
                }
            }
            if (s.size() != 9) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}