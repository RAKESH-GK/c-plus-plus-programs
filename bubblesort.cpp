# include<iostream>
using namespace std;
int  main()
{
 int a[10],size,i,j;
 cout<<"enter the size of array:";
 cin>>size;
 cout<<"enter the elements into array:\n";
 for(i=0;i<=size-1;i++)
 {
     cin>>a[i];
 }
 cout<<"array before sorting:\n";
 for(i=0;i<=size-1;i++)
 {
     cout<<a[i]<<" ";
 }
 cout<<"\narray after sorting:\n";
 for(i=0;i<=size-1;i++)
 {
 for (j=0;j<=size-i-1;j++)
 {
     if(a[j+1]<a[j])
     {
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
     }
 }    
 }
 for(i=0;i<=size-1;i++)
 {
     cout<<a[i]<<" ";
 }
    return 0;
}