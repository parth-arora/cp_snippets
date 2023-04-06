//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 200005
const ll N=32;
#define INF (ll)1e18
#define mod 1000000007
//#define mod 998244353
#define fi first
#define se second
#define mkp make_pair
#define clr(v)  v.clear()
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
#define level 20
ll timer,cc1,cc;

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


vector<ll> seg[4*MAXN];
ll a[MAXN];

void build(ll v , ll tl , ll tr)
{
	if(tl == tr)
	{
		seg[v].pb(a[tl]);
		return;
	}
	
	ll tm = (tl + tr) / 2;
	build(2*v , tl , tm);
	build(2*v + 1, tm+1 , tr);

	merge(all(seg[2*v]),all(seg[2*v+1]),back_inserter(seg[v]));
	
}

ll query(ll v , ll tl ,ll tr , ll l , ll r, ll k)
{
	if(l>r) 
	return 0;
	
	if(l==tl&&r==tr)
	{
		ll res = upper_bound(all(seg[v]), k) - seg[v].begin();
		return res;
	}
	
	ll tm= (tl+ tr) / 2;
	ll l1=query(2*v , tl , tm , l ,min(r,tm) , k);
	ll r1=query(2*v + 1 , tm + 1 , tr , max(l,tm+1) ,r, k);
	
	return l1 + r1;
}

// it gives us the number of elements lesser than or equal to k in a range 

int main()
{
	ll i,j,k,n,t,x,y,c=0,l,r;
    ll ans,h,z,m,u,q,mm,w,mx;
    ld f;

    boost();
    
	
	cin>>n>>q;

	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	build(1 , 1 , n);
	
	while(q--)
	{
		cin>>l>>r>>k;
		cout<<query(1 , 1 , n , l , r , k)<<endl;
	}

}

