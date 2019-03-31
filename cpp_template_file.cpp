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

#ifdef _WIN32
#define putchar_unlocked putchar
#define getchar_unlocked getchar
#endif

#define endl "\n"
#define fs first
#define sc second
#define pb emplace_back

#define rep(i,a,b) for (__typeof(b) i = (a); i < (b); ++i)
#define rrep(i,a,b) for (__typeof(b) i = (a); i > (b); --i)
#define iter(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define riter(it, c) for(__typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)
#define fillvec(c, n) c.reserve(n); for (__typeof(n) i = 0; i < (n); ++i) {__typeof(n) t; cin >> t; c.pb(t);}
#define checkvec(c) iter(it, c) {cout << *it << (it==(c).end()?"":" ");} cout << endl;

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

#pragma GCC diagnostic ignored "-Wregister"
void fs(ul &num) // fast scan unsigned long long
{register int c;num=0;c=getchar_unlocked();for(;(c>47&&c<58); c=getchar_unlocked())num=num*10+c-48;} 

void fs(ll &num) // fast scan long long
{  
    bool neg=false;register int c;num=0;c=getchar_unlocked();
    if(c=='-'){neg=true;c=getchar_unlocked();}
    for(;(c>47&&c<58); c=getchar_unlocked())num=num*10+c-48; 
    if(neg)num*=-1; 
}
void fp(ul num) { printf("%llu", num); } // fast print unsigned long long
void fp(ll num) { printf("%lld", num); } // fast print long long
void fpn(ul num) { printf("%llu\n", num); } // fast print unsigned long long with newline
void fpn(ll num) { printf("%lld\n", num); } // fast print long long with newline

#pragma GCC diagnostic pop

#pragma endregion


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
