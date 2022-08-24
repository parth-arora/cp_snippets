#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 100005
#define INF (ll)1e18
#define mod 1000000007 
//#define mod 998244353
#define endl '\n'
#define level 20
ll cc=0;

 
void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

 
vector<ll> st[4*MAXN];
pair<ll,ll> a[MAXN];
 
void build(ll si , ll ss , ll se)
{
    if(ss == se)
    {
        st[si].pb(a[ss].second);
        return;
    }
    
    ll mid = (ss + se) / 2;
    build(2*si , ss , mid);
    build(2*si + 1, mid+1 , se);
    
    ll i=0;
    ll j=0;
    
    while(i < st[2*si].size() && j < st[2*si+1].size())
    {
        if(st[2*si][i] <= st[2*si+1][j])
        st[si].pb(st[2*si][i]) , i++;
        
        else
        st[si].pb(st[2*si+1][j]) , j++;
    }
    
    while(i < st[2*si].size())
    st[si].pb(st[2*si][i]) , i++;
    
    while(j < st[2*si+1].size())
    st[si].pb(st[2*si+1][j]) , j++;
    
}
 
ll query(ll si , ll ss ,ll se , ll qs , ll qe , ll k)
{
    if(ss==se) 
    return st[si][0];
    
    /*
    if(ss >= qs && se <= qe)
    {
        ll res = upper_bound(st[si].begin() , st[si].end() , k) - st[si].begin();
        return res;
    }
    */
    
    ll p = upper_bound(st[2*si].begin(), st[2 *si].end(), qe) - lower_bound(st[2 * si].begin(), st[2 * si].end(), qs);
    
    ll mid = (ss + se) / 2;
    
    /*
    ll l = query(2*si , ss , mid , qs , qe , k);
    ll r = query(2*si + 1 , mid + 1 , se , qs , qe , k);
    */
    
    if (p >= k) 
    return query(2 * si, ss, mid, qs, qe, k);
    
    else
    return query(2*si+1, mid + 1, se, qs, qe, k - p); 
    
}



int main()
{
    boost();
    
    ll i,j,k,n,t,c=0,l,r,x,y;
    ll ans,h,z,m,u,q,mm,w,mx,d;
    ld f;
    
    cin>>x;
    
    cin>>n>>q;
    
    ll b[n+1];
    
    for(i=1;i<=n;i++)
    {
    cin>>b[i];
    a[i].first=b[i];
    a[i].second=i;
    }
    
    sort(a+1,a+n+1);
    
    build(1 , 1 , n);
    
    
    ans=0;
    // query answering goes here gives kth smallest element in a range 

    
    while(q--)
    {
        cin>>l>>r;
        y=(ans*x);
        
        k=l^y;
        z=r^y;
        
        w=query(1,1,n,1,z,k);
        ans=b[w];
        
        cout<<ans<<endl;
    
    }
    
    
return 0;
}
 