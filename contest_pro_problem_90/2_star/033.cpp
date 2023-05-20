#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <string.h>

typedef long l;
typedef long long ll;
using namespace std;


int main(){
    int h , w;
    cin >> h >> w;
    if( h == 1 || w == 1 ) cout << h*w << endl;
    else cout << ((w+1)/2) * ((h+1)/2) << endl;
    return 0;
}