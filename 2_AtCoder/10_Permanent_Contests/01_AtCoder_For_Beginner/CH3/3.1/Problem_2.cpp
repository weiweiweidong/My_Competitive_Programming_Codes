// https://atcoder.jp/contests/abc086/tasks/abc086_a

#include <iostream>
using namespace std;

int A, B;

int main() {
    scanf("%d%d", &A, &B);
    if (A * B % 2)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
}