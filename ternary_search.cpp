//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........
//https://codeforces.com/contest/2132/problem/E

 
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

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>t;
 
 while(t--)
 {
 cin>>n>>m>>q;
 vl g(n),g1(m);
 
 ll pre[n+1],pre1[m+1];
 memset(pre,0,sizeof(pre));
 memset(pre1,0,sizeof(pre1));
 
 for(i=0;i<n;i++)
 cin>>g[i];
 
 for(i=0;i<m;i++)
 cin>>g1[i];
 
 sort(all(g));
 sort(all(g1));
 reverse(all(g));
 reverse(all(g1));
 
 for(i=1;i<=n;i++)
 {
     pre[i]=pre[i-1]+g[i-1];
 }
 
 for(i=1;i<=m;i++)
 {
     pre1[i]=pre1[i-1]+g1[i-1];
 }
 
 ll m1,m2;
 
 while(q--)
 {
     cin>>x>>y>>z;
     
     l=max(ll(0),z-y);
     r=min(x,z);
     ans=0;
     
     while(r>l)
     {
         m1=(l+r)/2;
         m2=m1+1;
         
         l1=pre[m1]+pre1[z-m1];
         r1=pre[m2]+pre1[z-m2];
         
         if(l1<=r1)
         l=m2;
         
         else
         r=m1;
         
     }

     //l is the point where we find the maximum
     ans=pre[l]+pre1[z-l];
     
     cout<<ans<<endl;
     
 }
 
 }
  
return 0;
}
