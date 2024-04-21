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
    string S, T;
    cin >> S >> T;

    bool head = (T.substr(0, N) == S);
    bool tail = (T.substr(M - N, N) == S);

    if (head && tail)
        cout << 0 << endl;
    else if (head)
        cout << 1 << endl;
    else if (tail)
        cout << 2 << endl;
    else
        cout << 3 << endl;
}