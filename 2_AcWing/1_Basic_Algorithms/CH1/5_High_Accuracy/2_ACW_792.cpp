// Problem: https://www.acwing.com/problem/content/794/

// 高精度减法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 判断A是否大于B
bool cmp(vector<int>& A, vector<int>& B) {
    // 如果AB位数不同，位数大的大
    if (A.size() != B.size())
        return A.size() > B.size();
    // 如果AB位数相同，从高位开始一个个向下看
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

// 此时传进来的已经是A大于B了
vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        // 保存这一位的值
        C.push_back((t + 10) % 10);
        // 说明有借位
        if (t < 0)
            t = 1;
        // 否则置零
        else
            t = 0;
    }
    // 清除掉高位无效的0
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

void solve() {
    // 读入数据
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    // 从低位向高位，添加进AB数组中
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    // 计算减法
    vector<int> C;
    if (cmp(A, B))
        C = sub(A, B);
    else {
        C = sub(B, A);
        cout << "-";
    }

    // 输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
}