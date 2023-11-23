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

const int MAX_N = 200010;
char stk[MAX_N];
int sn;

int main() {
    string S;
    cin >> S;
    for (char c : S) {
        if (sn > 1 && stk[sn - 2] == 'A' && stk[sn - 1] == 'B' && c == 'C') {
            sn -= 2;
        } else {
            stk[sn] = c;
            sn++;
        }
    }
    stk[sn] = 0;
    cout << stk << endl;
}