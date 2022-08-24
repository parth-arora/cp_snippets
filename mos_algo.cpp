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
#define MAXN 1000005
#define MAXN1 200005
const ll N=750;
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

//https://atcoder.jp/contests/abc238/tasks/abc238_g

ll lp[MAXN],cnt[MAXN];
vl pr;
vpl fact[MAXN1];

void sieve() 
{ 
    ll i,j;
    
for (i=2; i <MAXN; ++i) 
{
    if (lp[i] == 0) 
    {
        lp[i] = i;
        pr.push_back(i);
    }
    
    for (j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] < MAXN; ++j) 
    {
        lp[i * pr[j]] = pr[j];
    }
}

}

bool comp(const pair<ll,pll> p, const pair<ll,pll> q) 
{
    if (p.fi /N != q.fi /N)
        return p < q;
        
    return (p.fi/N & 1) ? (p.se.fi< q.se.fi) : (p.se.fi > q.se.fi);
}

void rem(ll cur)
{
    ll c,x;
    
    for(auto y : fact[cur])
    {
        c=y.se;
        x=y.fi;
        
        if((cnt[x]%3)==0)
        {
            cnt[x]-=c;
            
            if((cnt[x]%3)!=0)
            cc++;
        }
        
        else if((cnt[x]%3)!=0)
        {
            cnt[x]-=c;
            
            if((cnt[x]%3)==0)
            cc--;
        }
        
    }
}

void add(ll cur)
{
    ll c,x;
    
    for(auto y : fact[cur])
    {
        c=y.se;
        x=y.fi;
        
        if((cnt[x]%3)==0)
        {
            cnt[x]+=c;
            
            if((cnt[x]%3)!=0)
            cc++;
        }
        
        else if((cnt[x]%3)!=0)
        {
            cnt[x]+=c;
            
            if((cnt[x]%3)==0)
            cc--;
        }
        
    }
}

int main()
{
 boost();
 sieve();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>q;
 vector<pair<ll,pll>> g;
 ll a[n+1],as[q+1];
 
 for(i=1;i<=n;i++)
 {
     cin>>a[i];
     
     z=a[i];
     
     while(z!=1)
     {
         c=0;
         x=lp[z];
         
         while(z%x==0)
         {
             z=z/x;
             c++;
         }
         
         fact[i].pb(mkp(x,c));
     }
 }
 
   cc=0;
 
      for(i=1;i<=q;i++)
      {
          cin>>l>>r;
          g.pb(mkp(l,mkp(r,i)));
      }
      
      sort(all(g),comp);
      
      l=1;
      r=0;
      
      for(auto it:g)
      {
          while(it.fi>l)
          {
              rem(l);
              l++;
          }
          
          while(it.fi<l)
          {
              l--;
              add(l);
          }
          
          while(it.se.fi>r)
          {
              r++;
              add(r);
          }
          
          while(r>it.se.fi)
          {
              rem(r);
              r--;
          }
          
          z=it.se.se;
          
          if(cc>0)
          as[z]=0;
          
          else
          as[z]=1;
          
      }
      
      for(i=1;i<=q;i++)
      {
          if(as[i]==0)
          cout<<"No"<<endl;
          
          else
          cout<<"Yes"<<endl;
      }
 
  
return 0;
}