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


vector<ll> st[4*MAXN];
ll a[MAXN];

void build(ll si , ll ss , ll se)
{
	if(ss == se)
	{
		st[si].pb(a[ss]);
		return;
	}
	
	ll mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si + 1, mid+1 , se);

	merge(all(st[2*si]),all(st[2*si+1]),back_inserter(st[si]));
	
}

ll query(ll si , ll ss ,ll se , ll qs , ll qe , ll k)
{
	if(ss > qe || se < qs) 
	return 0;
	
	if(ss >= qs && se <= qe)
	{
		ll res = upper_bound(st[si].begin() , st[si].end() , k) - st[si].begin();
		return res;
	}
	
	ll mid = (ss + se) / 2;
	ll l = query(2*si , ss , mid , qs , qe , k);
	ll r = query(2*si + 1 , mid + 1 , se , qs , qe , k);
	
	return l + r;
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

