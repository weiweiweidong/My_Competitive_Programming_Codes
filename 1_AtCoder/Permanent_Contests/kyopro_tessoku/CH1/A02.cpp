#include <iostream>
using namespace std;

int N, X;
int A[110];
bool res;

int main() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        if (A[i] == X)
            res = true;
    }

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}