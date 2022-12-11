#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
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
#define clr(v) v.clear()
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
typedef tree<ll, null_type,
             less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
 
    ordered_set;

ordered_set st[4*MAXN];
ll a[MAXN];

//https://codeforces.com/contest/785/problem/E
//https://discuss.codechef.com/t/point-updates-in-merge-sort-trees/59170

void build(ll si , ll ss , ll se)
{
	if(ss == se)
	{
		st[si].insert(a[ss]);
		return;
	}
	
	ll mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si + 1, mid+1 , se);
	
	for(auto x :st[2*si])
	st[si].insert(x);
	
	for(auto x :st[2*si+1])
	st[si].insert(x);
	
}

ll query(ll si , ll ss ,ll se , ll qs , ll qe , ll k)
{
	if(ss > qe || se < qs) 
	return 0;
	
	if(ss >= qs && se <= qe)
	{
		ll res = st[si].order_of_key(k);
		return res;
	}
	
	ll mid = (ss + se) / 2;
	ll l = query(2*si , ss , mid , qs , qe , k);
	ll r = query(2*si + 1 , mid + 1 , se , qs , qe , k);
	
	return l + r;
}

void update(ll si , ll ss ,ll se ,ll pos,ll ov,ll nv)
{
    if(pos>se||pos<ss)
    return;
    
    if(ss==se)
    {
        st[si].erase(st[si].find(ov));
        st[si].insert(nv);
        return;
    }
    
    ll mid=(ss+se)/2;
    update(2*si,ss,mid,pos,ov,nv);
    update(2*si+1,mid+1,se,pos,ov,nv);
    
    auto it=st[si].find(nv);
    
    if(it==st[si].end())
    {
    st[si].erase(st[si].find(ov));
    st[si].insert(nv);
    }
    
}


int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,j,tc,n,k;
 ll h,m,u,mm,w,x,y,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>q;
 
 for(i=1;i<=n;i++)
 {
     a[i]=i;
 }
 
 build(1,1,n);
 long long c=0,l1,z,r1;
 
 while(q--)
 {
     cin>>l>>r;
     
     if(l>r)
     swap(l,r);
     
     if(l==r)
     {
         cout<<c<<endl;
         continue;
     }
     
     
     z=r-l+1;
     
     l1=query(1,1,n,l,r,a[l]);
     c-=l1;
     l1=query(1,1,n,l,r,a[l]+1);
     c+=(z-l1);
     
     r1=query(1,1,n,l,r,a[r]+1);
     c-=(z-r1);
     r1=query(1,1,n,l,r,a[r]);
     c+=r1;
     
     if(a[l]>a[r])
     c++;
     
     else
     c--;
     
     
     update(1,1,n,l,a[l],a[r]);
     update(1,1,n,r,a[r],a[l]);
     
     swap(a[l],a[r]);
    
     
     cout<<c<<endl;
     
 }


  
  
return 0;
}