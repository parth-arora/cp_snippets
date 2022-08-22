//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 100005
const ll N=31;
#define INF (ll)1e18
#define mod 1000000007
//#define mod 998244353
#define fi first
#define se second
#define mkp make_pair
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
ll cc=0,cc1=0;
ll timer;


void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct node
{
    ll f=0;
    ll child[2]={0};
    
}nil;

vector<node> trie(1,nil);

void insert(ll num)
{
    ll cur=0,i,z,bit=0;
    
    for(i=N-1;i>=0;i--)
    {
        bit=0;
        if((1LL<<i)&num)
        {
            bit=1;
        }
        
        z=trie[cur].child[bit];
        
        if(z==0)
        {
            z=trie.size();
            trie[cur].child[bit]=z;
            trie.pb(nil);
        }
        
        cur=z;
        ++trie[cur].f;
        
    }
}

ll query(ll num)
{
    ll cur=0,i,z,bit=0,ans=0;
    
    for(i=N-1;i>=0;i--)
    {
        bit=0;
        if((1LL<<i)&num)
        {
            bit=1;
        }
        
        bit^=1;
        z=trie[cur].child[bit];
        
        if(z!=0)
        {
            ans+=(1LL<<i);
        }
        
        else
        {
            z=trie[cur].child[bit^1];
        }
        
        cur=z;
    }
    
    return ans;
}

void delet(ll num)
{
     ll cur=0,i,z,bit=0,ans=0;
     
     for(i=N-1;i>=0;i--)
    {
        bit=0;
        if((1LL<<i)&num)
        {
            bit=1;
        }
        
        z=trie[cur].child[bit];
        --trie[z].f;
        
        if(trie[z].f==0)
        {
            trie[cur].child[bit]=0;
        }
        
        cur=z;
        
    }
    
}


int main()
{
    boost();
 
    ll i,t,q,l,r,ans,mid,c,z,j,k,v;
    ll h,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f;
    
    cin>>q;
    char ch;
    insert(0);
    
    while(q--)
    {
        cin>>ch>>x;
        
        if(ch=='+')
        {
            insert(x);
        }
        
        else if(ch=='-')
        {
            delet(x);
        }
        
        else
        {
            ans=query(x);
            
            cout<<ans<<endl;
        }
    }
    
    
return 0;
}