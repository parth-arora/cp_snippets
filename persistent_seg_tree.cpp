//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
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

//https://cses.fi/problemset/task/1737
//https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-of-its-values-persistent-segment-tree

struct Vertex {
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(ll a[], ll tl, ll tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    ll tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

ll get_sum(Vertex* v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    ll tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}


int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>q;
 ll a[n+1];
 
 for(i=1;i<=n;i++)
 cin>>a[i];
 
 vector<Vertex*> g;
 
 Vertex* node=build(a,1,n);
 g.pb(node);
 
 while(q--)
 {
     cin>>y;
     cin>>k;
     
     if(y==1||y==2)
     {
         cin>>l>>r;
     }
     
     if(y==1)
     {
         Vertex* node=update(g[k-1],1,n,l,r);
         g[k-1]=node;
     }
     
     else if(y==2)
     {
         z=get_sum(g[k-1],1,n,l,r);
         cout<<z<<endl;
     }
     
     else
     {
         g.pb(g[k-1]);
     }
     
 }


  
  
return 0;
}