
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
typedef tree<ll, null_type,
             less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
ordered_set;

vpl generate(ll n)
{
    vpl g;
    vl g1;
    ordered_set ss;
    
    ll i,z,k,l,r;
    
    for(i=1;i<=n;i++)
    ss.insert(i);
    
    
    l=randnum(1,n);
    ss.erase(ss.find(l));
    g1.pb(l);
    
    
    while(1)
    {
        if(sze(ss)==0)
        break;
        
        l=randnum(1,sze(g1));
        z=randnum(1,sze(ss));
        r=*ss.find_by_order(z-1);
        g.pb(mkp(g1[l-1],r));
        g1.pb(r);
        ss.erase(ss.find(r));
    }
    
    return g;
    
    
}