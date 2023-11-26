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
    int N, Q;
    cin >> N >> Q;
    vector<int> cnt(N + 1);
    vector<int> A(N + 1);

    // 读入A，并维护cnt
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] <= N)
            cnt[A[i]]++;
    }

    // 维护一个 0～N 之间没出现的数字的 set
    set<int> nums;
    for (int i = 0; i <= N; i++) {
        if (cnt[i] == 0)
            nums.insert(i);
    }

    while (Q--) {
        int x, k;
        cin >> x >> k;
        if (A[x] <= N) {
            cnt[A[x]]--;
            if (cnt[A[x]] == 0)
                nums.insert(A[x]);
        }
        A[x] = k;
        if (A[x] <= N) {
            cnt[A[x]]++;
            if (cnt[A[x]] == 1)
                nums.erase(A[x]);
        }
        cout << *nums.begin() << endl;
    }
}