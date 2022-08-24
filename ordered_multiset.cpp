// Har Har Mahadev
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i)
        cin >> a[i];
    ordered_set<pii> s;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y),g[y].push_back(x);
    }
    auto med = [&]()
    {
        int n = sz(s);
        if(n & 1) {
            return s.find_by_order((n+1)/2-1) -> F;
        }
        int f = s.find_by_order(n/2-1) -> F;
        int g = s.find_by_order(n/2) -> F;
        return (f + g)/2;
    };
    vector<int> dp(n+1,0),dep(n+1,0);
    function<int(int,int)> dfs = [&](int u,int p)
    {
        s.insert({a[u],u});
        if(sz(g[u]) == 1 && u != 1) {
            auto f = med();
            s.erase({a[u],u});
            return f;
        }
        vector<int> t;
        for(auto &j:g[u]) {
            if(j == p)
                continue;
            dep[j] = dep[u] + 1;
            t.push_back(dfs(j,u));
        }
        sort(all(t));
        if(dep[u] & 1) {
            dp[u] = t[0];
        }
        else {
            dp[u] = t.back();
        }
        s.erase({a[u],u});
        return dp[u];
    };
    cout << dfs(1,0) << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}