#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct item
{
    float value;
    float weight;
    float rat;

};

bool comp( item a1,item a2)
{
    return a1.rat>a2.rat;
}

int main()
{
    ll i,j,k,n;
float v=0.0,w=0.0,W=0.0,z=0.0;

cout<<"Enter no. of items"<<endl;
cin>>n;

cout<<"Enter weight of knapsack"<<endl;
cin>>W;

item d[n];

cout<<"Enter value and weight of each item"<<endl;

for(i=0;i<n;i++)
{
    cout<<"Enter the details of "<<i+1<<" item:"<<endl;
    cin>>d[i].value;
    cin>>d[i].weight;
}

for(i=0;i<n;i++)
{
    d[i].rat=(d[i].value/d[i].weight);
}

    sort(d,d+n,comp);
    for (i = 0;i<n; i++)
    {
        if ((w+ d[i].weight )<= W)
        {
            w+= d[i].weight;
            v+= d[i].value;
        }

        else
        {
            z= W-w;
            v+=d[i].value*(z/d[i].weight);
            break;
        }
    }

    cout<<"the max value is:"<<endl;
    cout<<(float)v<<endl;

	return 0;
}

