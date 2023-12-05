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
using namespace std;
const int N = 55;
int n, m;
int w[N][N];
int f[N + N][N][N];

int main() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout << "set 的 size 值为 ：" << s.size() << endl;
    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
    cout << "set 中的第一个元素是 ：" << *s.begin() << endl;
    cout << "set 中的最后一个元素是:" << *s.end() << endl;
    // s.clear();
    if (s.empty()) {
        cout << "set 为空 ！！！" << endl;
    }
    cout << "set 的 size 值为 ：" << s.size() << endl;
    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;

    cout << *s.lower_bound(1) << endl;
    cout << *s.upper_bound(1) << endl;
    return 0;
}