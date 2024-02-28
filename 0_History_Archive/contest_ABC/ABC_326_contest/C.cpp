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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // A[N] = -1e9 - 1;
    // A[N + 1] = 1e9 + 1;
    int res = 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        int a = A[i], b = a + M;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        res = max(pos - i, res);
    }

    cout << res << endl;
}