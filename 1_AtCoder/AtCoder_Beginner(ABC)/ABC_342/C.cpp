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
    string S;
    cin >> S;
    vector<int> c_map(26);
    for (int i = 0; i < 26; i++)
        c_map[i] = i;

    int Q;
    cin >> Q;
    while (Q--) {
        char a, b;
        cin >> a >> b;
        for (int i = 0; i < 26; i++) {
            if (c_map[i] == (a - 'a'))
                c_map[i] = (b - 'a');
        }
    }

    for (auto x : S) {
        cout << (char)('a' + c_map[x - 'a']);
    }
    cout << endl;
}