#include<iostream>
#include<stdlib.h>
#include<algorithm> // this header is used for in-built sort function of c++.
using namespace std;
typedef long long int ll;
int main()
{
 int t,flag;
 ll n,*arr,i;
 cin>>t;
 while(t--)
 {
 cin>>n;
 arr=(ll *)malloc(sizeof(ll)*n);
 for(i=0;i<n;i++)
 {
 cin>>arr[i];
 }
 sort(arr,arr+n); // it takes 2 iterators and performs sorting in between these start and end iterator(nothing but a pointer).It performs sorting in O(nLogn).
 flag=0;
 for(i=1;i<n;i++)
 {
 if(arr[i]-arr[i-1]>1) // checking that whether it exceeded 1 or not
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 cout<<"YES\n";
 }
 else
 {
 cout<<"NO\n";
 }
 }
}
