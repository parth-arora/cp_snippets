#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void route(ll n,ll a,ll b)
{
	ll at=0,bt=0;
	cout<<"(0,0)\n";
	while(at!=n&&bt!=n)
	{
		if(at==0)
		{
			at=a;
			cout<<"("<<at<<","<<bt<<")"<<endl;;
		}
		else if(bt==b)
		{
			bt=0;
			cout<<"("<<at<<","<<bt<<")"<endl;;
		}
		else
		{
			int mini=min(at,b-bt);
			at-=mini;
			bt+=mini;
			cout<<"("<<at<<","<<bt<<")"<<endl;;
		}
	}
}


int main()
{
	ll i,j,k,c=0,z,t,m,l,r,a,b,n;
	cout<<"Enter capacity of first and second jug  and amount of water u want to fill respectively : ";
	cin>>a>>b>>n;

	k=__gcd(a,b);

	if((n<a||n<b)&&((n%k)==0))
	{
		cout<<"\n route of filling in jugs:\n";
		route(n,a,b);
	}

	else
    cout<<"\nNot possible to fill water\n";

	return 0;
}

