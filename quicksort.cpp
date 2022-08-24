#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp(ll a[],ll l,ll r)
{
    ll p,k,c,e;

    p=a[r];
    k=(l- 1);
    for (e=l;e<=(r-1);e++)
    {
        if (a[e]<=p)
        {
        k++;
        swap(a[k],a[e]);
        }
    }
    swap(a[r],a[k+1]);
    c=k+1;
    return (c);
}
ll entp()
{
ll pv;
cout<<"Enter the index of random pivot to be selected:"<<endl;
cin>>pv;
}

ll fp(ll a[],ll l,ll r,ll s)
{
    ll rd;
    rd=(s%(r-l));
    rd+=l;
    swap(a[rd],a[r]);

    return dp(a,l,r);
}


void fsa(ll a[],ll l,ll r,ll s)
{
    ll pvi;
    if (l<r)
        {
        pvi=fp(a,l,r,s);
        fsa(a,l,pvi-1,s);
        fsa(a,pvi+1,r,s);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll i,j,k,n,c=0,z,t,q,pv;

cout<<"Enter size of array:"<<endl;
cin>>n;

ll d[n];

cout<<"Enter elements of array:"<<endl;

for(i=0;i<n;i++)
cin>>d[i];

cout<<"Enter the index of random pivot to be selected:"<<endl;
cin>>pv;

fsa(d,0,n-1,pv);

cout<<"Sorted array is:"<<endl;

for(i=0;i<n;i++)
cout<<d[i]<<" ";

    return 0;
}
