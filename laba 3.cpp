#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int p[100],a[100];
int T,i;
cin>>T;
for(i=0;i<T;i++) 
{
cin>>a[i]; if(a[i]<1) break; 
}
for(i=0;i<T;i++)
{
p[i]=log(a[i])/log(2);
}
for(i=0;i<T;i++)
cout<<p[i]<<endl;
system("PAUSE");
    return EXIT_SUCCESS;
}
