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
    int a ,b;
    cin >> a >> b;
    if( a%2!=0 && b%2!=0){
        cout << "Odd" << endl;
    }
    else cout << "Even" << endl;

    return 0;
}