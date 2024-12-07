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

string S, T;
int N, M;

void check(int pos) {
    bool found = 0;
    for (int i = 0; i < M; i++) {
        if (S[pos + i] != '#') {
            if (S[pos + i] == T[i])
                found = 1;
            else
                return;
        }
    }

    if (found) {
        for (int i = 0; i < M; i++)
            S[pos + i] = '#';

        for (int j = pos - M + 1; j < pos + M - 1 && j + M <= N; j++)
            check(j);
    }
}

int main() {
    cin >> N >> M >> S >> T;
    for (int i = 0; i + M <= N; i++) {
        check(i);
    }

    cout << (S == string(N, '#') ? "Yes" : "No") << endl;
}