ll basis[N];

 
 
void insert(ll mask)
{
    ll i;
    
    for(i=0;i<N;i++)
    {
        if(!(mask&(1LL<<i)))
        {
            continue;
        }
        
        if(!basis[i])
        {
            basis[i]=mask;
            cc++;
            return;
        }
        
        mask^=basis[i];
    }
}
 
bool check(ll mask)
{
    ll i;
    
    for(i=0;i<N;i++)
    {
        if(!(mask&(1LL<<i)))
        continue;
        
        if(basis[i]==0)
        return false;
        
        
        mask^=basis[i];
    }
    
    return true;
}