ll lp[MAXN];
vl pr;


void sieve() 
{ 
    ll i,j;
    
for (i=2; i <MAXN; ++i) 
{
    if (lp[i] == 0) 
    {
        lp[i] = i;
        pr.push_back(i);
    }
    
    for (j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] < MAXN; ++j) 
    {
        lp[i * pr[j]] = pr[j];
    }
}

lp[0]=-1;

}