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

int sum_cal(vector<int> A) {
    int n = A.size();
    int sum = 0;
    int min_A = 1e8, max_A = -1;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        min_A = min(min_A, A[i]);
        max_A = max(max_A, A[i]);
    }
    return sum - min_A - max_A;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N - 1; i++)
        cin >> A[i];

    for (int num = 0; num <= 100; num++) {
        A[N - 1] = num;

        int res = sum_cal(A);
        if (res >= X) {
            cout << num << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}