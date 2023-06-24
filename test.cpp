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


#include<type_traits>

using namespace std;
int main()
{
    int i=1;
    auto&& x{i};
    auto&& y{2};

    cout<< is_same_v<int&,decltype(x)> << endl; //true
    cout<< is_same_v<int&&,decltype(y)> << endl; // true
    
    cout<< is_same_v<int&&,decltype(x)> << endl; //true
    cout<< is_same_v<int&,decltype(y)> << endl; // true
}