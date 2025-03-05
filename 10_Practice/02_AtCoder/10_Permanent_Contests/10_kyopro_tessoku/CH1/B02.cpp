#include <iostream>
using namespace std;

int A, B;
bool res;

int main() {
    cin >> A >> B;
    for (int i = A; i <= B; i++) {
        if (100 % i == 0)
            res = true;
    }

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}