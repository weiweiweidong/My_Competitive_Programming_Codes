#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <string.h>

typedef long L;
typedef long long LL;
using namespace std;


int main(){
    string s;
    cin >> s;

    int res = 0;
    for( auto c : s ){
        if( c == '1' ) res++;
    }
    cout << res << endl;
}