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
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;

    for (int i = 1; i < N; i++) {
        if (A[i - 1] > A[i]) {
            for (int j = A[i - 1]; j > A[i]; j--) {
                cout << j << " ";
            }
        } else {
            for (int j = A[i - 1]; j < A[i]; j++) {
                cout << j << " ";
            }
        }
    }
    cout << A[N - 1] << endl;
}