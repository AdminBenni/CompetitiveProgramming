#pragma region includes and predefines
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>

#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
#pragma GCC optimize("tree-parallelize-loops=4")

using namespace std;

#ifndef __typeof
#define __typeof(T) decltype(T)
#endif

#define endl "\n"
#define fs first
#define sc second
#define pb emplace_back

#define rep(i,a,b) for (__typeof(b) i = (a); i < (b); ++i)
#define iter(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef long long ll;
typedef unsigned long long ul;
typedef pair<ll,ll> pl;
typedef pair<ul,ul> pu;
typedef vector<ll> vl;
typedef vector<ul> vu;
typedef vector<vl> vl2;
typedef vector<vu> vu2;

#pragma GCC diagnostic ignored "-Wshift-count-overflow"
const ll inf = ~(1<<31);
const ul inf_u = ~(1<<32);
#pragma GCC diagnostic pop

const double dlo = 1e-9;
const double pi = acos(-1);

#pragma endregion


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
