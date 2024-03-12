// Problem: https://www.acwing.com/problem/content/796/

// 高精度除法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

vector<int> div(vector<int>& A, int b, int& r) {
    vector<int> C;
    r = 0;

    // 从高位往低位运算
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    /*
        这里计算出来的结果是从高位往低位排的。为了去除前导零，以及和前几道题的结果相匹配，这里改成从低位到高位
    */
    reverse(C.begin(), C.end());
    // 去除前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

void solve() {
    string a;
    vector<int> A;
    int b;
    cin >> a >> b;

    /*
        实际上只是计算除法的话，从高往低存入A更合适。为了和前面加减乘的处理方式一致，这里还是从低位到高位存储进入A
     */
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    // 计算除法
    int r;
    auto C = div(A, b, r);

    // 输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    // 输出余数
    cout << endl << r << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}