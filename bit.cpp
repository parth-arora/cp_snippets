ll tree[MAXN];
 
ll sum(ll indx) 
{ 
    ll sum=0;
  
    while (indx>0) 
    { 
        sum=sum+tree[indx]; 
  
        indx -= indx & (-indx); 
    }
    
    return sum; 
} 
 
void update(ll indx, ll val) 
{ 
    ll i,j;
  
    while (indx<MAXN) 
    { 
    tree[indx]+= val; 
 
    indx += indx & (-indx); 
    }
    
}