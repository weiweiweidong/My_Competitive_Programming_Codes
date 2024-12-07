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

int N;
string S;
int main() {
    cin >> N >> S;
    int a = 0, b = 0;
    for (auto c : S) {
        if (c == 'T')
            a++;
        else
            b++;

        if (a >= (N + 1) / 2) {
            cout << "T" << endl;
            return 0;
        } else if (b >= (N + 1) / 2) {
            cout << "A" << endl;
            return 0;
        }
    }
}