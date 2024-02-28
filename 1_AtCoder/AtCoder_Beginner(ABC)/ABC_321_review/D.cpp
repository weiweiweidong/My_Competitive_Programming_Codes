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

// 使用双指针或 二分都可以做
int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<LL> A(N);
    vector<LL> B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int j = 0; j < M; j++)
        cin >> B[j];
    sort(A.begin(), A.end());

    vector<LL> sum_A(N + 1);
    for (int i = 1; i <= N; i++)
        sum_A[i] = sum_A[i - 1] + A[i - 1];

    LL res = 0;
    for (int i = 0; i < M; i++) {
        LL a = P - B[i];
        int pos = lower_bound(A.begin(), A.end(), a) - A.begin();

        res += (LL)B[i] * pos + sum_A[pos] + ((LL)N - pos) * P;
    }

    cout << res << endl;
}