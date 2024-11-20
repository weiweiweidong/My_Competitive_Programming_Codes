// Problem: https://www.acwing.com/problem/content/793/

// 高精度加法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 高精度加法（本质上是在模拟真实的加法计算过程）
vector<int> add(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size())
        return add(B, A);

    vector<int> C;
    // 保存进位信息
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    // 如果最后进位不为0，就把他加到C里
    if (t)
        C.push_back(t);
    return C;
}

void solve() {
    // 读入字符串
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    // 把字符串从低位到高位，转化为数字，插到AB数组中
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    // 求解
    auto C = add(A, B);
    // 从高位到低位输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
}