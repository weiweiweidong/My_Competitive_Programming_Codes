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


ll gcd( ll a , ll b ){
    return b ? gcd(b , a%b ) : a ;
}

int main(){
    ll A , B , C;
    cin >> A >> B >> C;
    ll x = gcd(A , B);
    x = gcd(x , C);
    
    ll res =0;
    res += (A/x - 1);
    res += (B/x - 1);
    res += (C/x - 1);
    cout << res << endl;

    return 0;
        
}