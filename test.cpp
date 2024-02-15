#include <iostream>
using namespace std;
const int N = 1e6;

struct Node {
    int cnt;
    int nd[26];
};

class Trie {
    Node m_tr[N + 1];
    int len;

   public:
    Trie(){};
    ~Trie(){};
    void insert(string str);
    bool search(string str);
};

void Trie::insert(string str) {
    int slen = str.size(), p = 0;
    for (int i = 0; i < slen; i++) {
        if (m_tr[p].nd[str[i] - 'a'] == 0) {
            len++;
            m_tr[p].nd[str[i] - 'a'] = len;
        }
        p = m_tr[p].nd[str[i] - 'a'];
    }
    m_tr[p].cnt++;
}

bool Trie::search(string str) {
    int slen = str.size(), p = 0;
    for (int i = 0; i < slen; i++) {
        p = m_tr[p].nd[str[i] - 'a'];
        if (p == 0)
            return false;
    }
    return m_tr[p].cnt;
}

Trie tr;
int main() {
    int n, op;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op >> s;
        if (op == 1)
            tr.insert(s);
        else {
            cout << (tr.search(s) ? "Yes" : "No") << endl;
        }
    }
}