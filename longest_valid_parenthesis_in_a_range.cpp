//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
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

struct node
{
    ll l,r,m;
};
 
 
node seg[4 * MAXN];
 
node merge(node n1,node n2)
{
    node p;
    
    ll l1=min(n1.l,n2.r);
    p.m=n1.m+n2.m+l1;
    p.l=n1.l+n2.l-l1;
    p.r=n1.r+n2.r-l1;
    
    return p;
}
 
node make(ll val,ll val1)
{
    node p;
    
    p.l=val;
    p.r=val1;
    p.m=0;
    
    return p;
}
 
 
node sum(ll v, ll tl, ll tr, ll l, ll r)
{
    ll tm, i, j;
    node p1,p2,p;
 
    if (l > r)
    {
        j=0;
        p=make(j,j);
        return p;
    }
 
    if (l == tl && r == tr)
    {
        return seg[v];
    }
 
    tm = (tl + tr) / 2;
    
     p1=sum(v * 2, tl, tm, l, min(r, tm));
     p2=sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
     
     p=merge(p1,p2);
 
    return p;
}
 
 
void update(ll v, ll tl, ll tr, ll pos, ll val,ll val1)
{
    ll tm, i, j;
 
    if (tl == tr)
    {
        seg[v]=make(val,val1);
    }
 
    else
    {
        tm = (tl + tr) / 2;
 
        if (pos <= tm)
        {
            update(v * 2, tl, tm, pos, val,val1);
        }
 
        else
        {
            update(v * 2 + 1, tm + 1, tr, pos, val,val1);
        }
        
        seg[v]=merge(seg[v*2],seg[v*2+1]);
        
    }
}

int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  cin>>n>>q;
  string s;
  
  cin>>s;
  
  
  
  for(i=0;i<n;i++)
  {
      if(s[i]=='(')
      {
          update(1,1,n,i+1,1,0);
      }
      
      else
      {
          update(1,1,n,i+1,0,1);
      }
  }
  
  while(q--)
  {
      cin>>y>>l>>r;
      
      if(y==1)
      {
          l--;
          r--;
          c=0;
          d=0;
          
          if(s[l]!=s[r])
          {
              if(s[r]=='(')
              c++;
              
              else
              d++;
              
              update(1,1,n,l+1,c,d);
              update(1,1,n,r+1,d,c);
          }
          
          swap(s[l],s[r]);
      }
      
      else
      {
          auto p=sum(1,1,n,l,r);
          z=p.m;
          z*=2;
          
          if(z==(r-l+1))
          cout<<"Yes"<<endl;
          
          else
          cout<<"No"<<endl;
      }
  }


   
   
return 0;
}