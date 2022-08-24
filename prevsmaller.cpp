#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

int main()
{
    boost();

    ll i,j,k,n,c=0,d=0,t,x,y;
    ll l,r,ans,h,f,z,m;
    vector<ll> v;

    cin>>n;
    pair<ll,ll> a[n];
    ll b[n];

    for(i=0;i<n;i++)
    {
    cin>>j;
    a[i].first=j;
    a[i].second=i;
    }

    stack <pair<ll,ll>> s;
    s.push(a[n-1]);

    for(i=n-2;i>=0;i--)
    {
        while((!s.empty())&&(s.top().first>a[i].first))
        {
            b[s.top().second]=a[i].first;
            s.pop();
        }

    s.push(a[i]);
    }

    while((!s.empty()))
    {
        b[s.top().second]=-1;
        s.pop();
    }

    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }

return 0;
}
