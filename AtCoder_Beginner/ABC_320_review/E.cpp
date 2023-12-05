#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> appear;
    for (int i = 1; i <= N; i++)
        appear.insert(i);
    vector<LL> res(N + 1);
    set<vector<int>> events;

    while (M--) {
        int T, W, S;
        cin >> T >> W >> S;
        events.insert({T, W, S});
    }

    while (!events.empty()) {
        auto event = *events.begin();
        events.erase(events.begin());

        if (event[1] < 0)
            appear.insert(-event[1]);
        else {
            if (appear.empty())
                continue;
            int id = *appear.begin();
            res[id] += event[1];
            appear.erase(id);
            events.insert({event[0] + event[2], -id});
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << endl;
    }
}