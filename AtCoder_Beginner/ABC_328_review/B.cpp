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
    int N;
    cin >> N;

    int res = 0;
    for (int month = 1; month <= N; month++) {
        int D;
        cin >> D;
        for (int day = 1; day <= D; day++) {
            string str = to_string(month) + to_string(day);
            if (count(str.begin(), str.end(), str[0]) == str.size())
                res++;
        }
    }
    cout << res << endl;
}