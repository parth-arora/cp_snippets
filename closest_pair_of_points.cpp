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
#define INF (ll)9e18
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

vpl p,tmp;
pair<pll,pll> as;
map<pll,ll> mp;
 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
ll dis(pll p1,pll p2)
{
    ll z;
    z=(p1.fi-p2.fi)*(p1.fi-p2.fi)+(p1.se-p2.se)*(p1.se-p2.se);
    
    return z;
}
 
void  brute(ll l,ll r)
{
    ll i,j,z;
    
    for(i=l;i<r;i++)
    {
        for(j=i+1;j<r;j++)
        {
            z=dis(p[i],p[j]);
            
            if(cc>z)
            {
                as=mkp(p[i],p[j]);
            }
            
            cc=min(cc,z);
        }
    }
}
 
void  stripe(pll strip[],ll n)
{
    ll i,j,z,ans;
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            z=strip[j].se-strip[i].se;
            
            if((z*z)>cc)
            {
                break;
            }
            
            else
            {
                z=dis(strip[j],strip[i]);
                
            if(cc>z)
            {
                as=mkp(strip[i],strip[j]);
            }
                cc=min(cc,z);
            }
        }
    }
    
}

bool comp(const pll &p1,const pll &p2)
{
    return p1.se<p2.se;
}
 
void find(ll l,ll r)
{
    ll mid,i,j,ans,z,n;
    pll mp;
    
    n=r-l;
    
    if(n<=3)
    {
        brute(l,r);
        sort(p.begin()+l,p.begin()+r,comp);
        return ;
    }
    
    mid=(l+r)/2;
    mp=p[mid];
   
    
    find(l,mid);
    find(mid,r);
    
    merge(p.begin()+l,p.begin()+mid,p.begin()+mid,p.begin()+r,tmp.begin(),comp);
    copy(tmp.begin(),tmp.begin()+n,p.begin()+l);
    
    
    pll strip[n];
    j=0;
    
    for(i=l;i<r;i++)
    {
        z=(p[i].fi-mp.fi)*(p[i].fi-mp.fi);
        
        if(z<cc)
        {
            strip[j]=p[i];
            j++;
        }
    }
    
    stripe(strip,j);
    
}
 
 
 
int main()
{
    boost();
    
    ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
    ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
    ld f,f1;
    
    cin>>n;
    tmp.resize(n);
    cc=INF;
    
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        p.pb(mkp(x,y));
        mp[mkp(x,y)]=i;
    }
    
    sort(all(p)); 
    
    find(0,n);
    
    f1=(ld)sqrtl(cc);
    l=mp[as.fi];
    r=mp[as.se];
    
    l1=min(l,r);
    r1=max(l,r);
    
    cout<<l1<<" "<<r1<<" ";
    cout<<fixed<<setprecision(6)<<f1<<endl; 
    
 
 
    
    
return 0;
}