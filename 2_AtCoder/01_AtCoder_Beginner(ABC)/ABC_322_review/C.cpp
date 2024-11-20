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
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> A[i];

    for (int i = 1, k = 1; i <= N; i++) {
        if (i < A[k])
            cout << A[k] - i << endl;
        else if (i == A[k]) {
            cout << 0 << endl;
            k++;
        }
    }
}