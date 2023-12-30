// https://atcoder.jp/contests/abc153/tasks/abc153_a

#include <iostream>
using namespace std;

int H, A;

int main() {
    scanf("%d%d", &H, &A);
    if (H % A)
        cout << H / A + 1 << endl;
    else
        cout << H / A << endl;
}