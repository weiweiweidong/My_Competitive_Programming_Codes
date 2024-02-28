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

LL trans(string& s) {
    LL res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 2 + (s[i] - '0');
    return res;
}

// 使用贪心的思想
int main() {
    string S;
    LL N;
    cin >> S >> N;

    queue<int> pos;
    for (int i = 0; i < S.size(); i++)
        if (S[i] == '?') {
            pos.push(i);
            S[i] = '0';
        }
    if (trans(S) > N) {
        cout << "-1" << endl;
        return 0;
    }

    while (pos.size()) {
        int i = pos.front();
        pos.pop();
        S[i] = '1';
        if (trans(S) > N)
            S[i] = '0';
    }

    cout << trans(S) << endl;
}