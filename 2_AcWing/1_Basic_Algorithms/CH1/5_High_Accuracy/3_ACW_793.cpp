// Problem: https://www.acwing.com/problem/content/795/

// 高精度乘法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 高精度 乘以 低精度
vector<int> mul(vector<int>& A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

void solve() {
    // 读入数据
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    // 从低位到高位，把数据放入A
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    // 计算乘法
    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}