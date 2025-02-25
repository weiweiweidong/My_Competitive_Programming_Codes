// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

stack<char> stk;
string s;

bool check(char x) {
    if (x == ')' && stk.top() == '(')
        return true;
    else if (x == ']' && stk.top() == '[')
        return true;
    else if (x == '>' && stk.top() == '<')
        return true;
    else
        return false;
}

void solve() {
    cin >> s;

    for (auto x : s) {
        // 遇到左括号，就入栈
        if (x == '(' || x == '[' || x == '<')
            stk.push(x);
        // 遇到右括号
        else {
            // 如果栈已经空了，遇到右括号肯定不能正常运行
            // 如果不能正常消掉右括号，肯定也不能正常运行
            // 程序直接结束就行了
            if (stk.empty() || !check(x)) {
                cout << "No" << endl;
                return;
            }
            stk.pop();
        }
    }

    // 看一下最后栈是否为空
    cout << (stk.empty() ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}