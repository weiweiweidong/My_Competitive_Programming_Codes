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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> C;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        C.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        if (C[i] == A + B) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}