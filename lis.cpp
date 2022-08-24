#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef long double ld;
#define MAXN 200005
#define INF (ll)1e18
#define mod 1000000007
#define endl '\n'

ll tree[MAXN];

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

ll sum(ll indx)
{
    ll sum=0;

    while (indx>0)
    {
        sum=max(sum,tree[indx]);

        indx -= indx & (-indx);
    }

    return sum;
}

void update(ll n, ll indx,ll val)
{
    ll i,j,x,value;

    while (indx <=n)
    {
    tree[indx]=max(tree[indx],val);

    indx += indx & (-indx);
    }

}



int main()
{
    boost();

    ll i,j,k,n,c=0,t,x,y;
    ll l,r,ans,h,z,m,u,q,p,mx;


    cin>>n;

    ll a[n],b[n];

    for(i=0;i<n;i++)
    {
    cin>>a[i];
    b[i]=a[i];
    }


      for(i=0;i<=n;i++)
    {
        tree[i]=0;
    }

    sort(b,b+n);

    for(i=0;i<n;i++)
    {
        a[i]=lower_bound(b,b+n,a[i])-b+1;
        x=sum(a[i]-1)+1;

        update(n,a[i],x);
    }

    mx=sum(n);


    cout<<mx<<endl;

return 0;
}
