// 扩展域的写法

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 40010, BASE = N / 2;
int n, m;
int p[N];
unordered_map<int, int> S;

int get(int x) {
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    n = 0;
    for (int i = 0; i < N; i++)
        p[i] = i;

    int res = m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b);

        if (type == "even") {
            if (find(a + BASE) == find(b)) {
                res = i - 1;
                break;
            }
            p[find(a)] = find(b);
            p[find(a + BASE)] = find(b + BASE);
        } else {
            if (find(a) == find(b)) {
                res = i - 1;
                break;
            }
            p[find(a + BASE)] = find(b);
            p[find(a)] = find(b + BASE);
        }
    }
    cout << res << endl;
    return 0;
}