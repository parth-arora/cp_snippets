
#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double ld;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<ll, null_type,
             less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>

    ordered_set;

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

int main()
{
    boost();

    ll i,j,k,n,c=0,d=0,t,x,y;
    ll l,r,ans,h,f,m,z;

    cin>>n;
    map<ll,ll> M;
    M.clear();

    ll a[n+1];

    for(i=1;i<=n;i++)
    cin>>a[i];

    c=0;
    d=INT_MIN;
    z=1;


    for(i=1;i<=n;i++)
    {
        if(M[a[i]]==0)
        {
            M[a[i]]=i;
            continue;
        }

        else
        {
            j=M[a[i]];

            if(j>=z)
            {
                l=i-1-z+1;
                d=max(d,l);
                z=j+1;
            }

            else if(z>j)
            {
                l=i-z+1;
                d=max(d,l);

            }

            M[a[i]]=i;
        }
    }

    d=max(d,n-z+1);

    cout<<d<<endl;


return 0;
}
