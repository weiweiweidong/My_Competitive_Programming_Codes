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

typedef long L;
typedef long long LL;
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int res = -1;
    for (int i = 1; i < N; i++) {
        if (S[i - 1] == '-' && S[i] == 'o') {
            int j = i;
            while (j < N && S[j] == 'o')
                j++;
            res = max(j - i, res);
            i = j;
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        if (S[i + 1] == '-' && S[i] == 'o') {
            int j = i;
            while (j >= 0 && S[j] == 'o')
                j--;
            res = max(res, i - j);
            i = j;
        }
    }

    cout << res << endl;
}