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
using namespace std;

typedef long L;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    string S, T;
    cin >> S >> T;
    set<int> h{'a' - 'a', 't' - 'a', 'c' - 'a', 'o' - 'a',
               'd' - 'a', 'e' - 'a', 'r' - 'a'};

    vector<int> A(27), B(27);
    for (auto x : S) {
        if (x == '@')
            A[26]++;
        else
            A[x - 'a']++;
    }
    for (auto x : T) {
        if (x == '@')
            B[26]++;
        else
            B[x - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        // 如果数量相同
        if (A[i] == B[i])
            continue;
        // 如果数量不同
        else {
            // 1. 是atcoder字母之一
            if (h.count(i)) {
                if (A[i] > B[i])
                    B[26] -= (A[i] - B[i]);
                else
                    A[26] -= (B[i] - A[i]);
            }
            // 2. 不是atcoder字母之一
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    if (A[26] == B[26] && A[26] >= 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}