ll mob[MAXN];

void cal()
{
    ll i,j,k,c=0,z,d=0,l,x;
    
    mob[1]=1;
    
    for(i=2;i<MAXN;i++)
    {
        z=i;
        d=0;
        l=0;
        
        while(z!=1)
        {
            x=spf[z];
            c=0;
            d++;
            
            while((z%x)==0)
            {
                c++;
                z=(z/x);
            }
            
            if(c>1)
            l++;
        }
        
        if(l>0)
        mob[i]=0;
        
        else
        {
            if(d&1)
            mob[i]=-1;
            
            else
            mob[i]=1;
        }
    }
}