#include <math.h>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long L;
typedef long long LL;

typedef pair<LL, LL> PII;
const int N = 200010;
int n, m;
LL h[N], e[2 * N], w[2 * N], ne[2 * N], idx;
LL dist[N];
bool st[N];

void add(LL a, LL b, LL c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

LL dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = (LL)0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        LL ver = t.second, distance = t.first;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f3f3f3f3f)
        return -1;
    return dist[n];
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        add(i, i + 1, a);
        add(i, c, b);
    }
    cout << dijkstra() << endl;
    return 0;
}