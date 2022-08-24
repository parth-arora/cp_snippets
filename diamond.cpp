
#include<bits/stdc++.h>
using namespace std;
int main()

{
    int i,j,k,n,c=0;
    cout<<"Enter value of n:"<<endl;
    cin>>n;

  for(i=1;i<=n;i++)
  {

      for(j=1;j<=n-i;j++)
      cout<<" ";

      for(j=n;j>n-i;j--)
        cout<<2*i-j+n-1;

    for(j=n+1;j<n+i;j++)
        cout<<"*";

cout<<endl;


  }


    return 0;
}
