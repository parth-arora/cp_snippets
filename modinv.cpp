
ll power(ll x,ll y,ll m)
{
    ll res=1;
    x=x%m;

    while(y>0)
    {
        if(y&1)
        {
            res=res*x;
            res=res%m;
        }

        y=y>>1;

            x=x*x;
            x=x%m;
    }

    return res;
}

ll modinv(ll n,ll m)
{
    return power(n,m-2,m);
}

