void ifdef()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//remove ifndef and endif in codeforces while submitting

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll randnum(ll l,ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}