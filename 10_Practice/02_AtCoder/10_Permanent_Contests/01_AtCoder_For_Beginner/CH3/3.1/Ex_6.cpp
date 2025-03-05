// https://atcoder.jp/contests/abc064/tasks/abc064_a

#include <iostream>
using namespace std;

int r, g, b;

int main() {
    cin >> r >> g >> b;
    int t = r * 100 + g * 10 + b;
    cout << (t % 4 ? "NO" : "YES") << endl;
}
