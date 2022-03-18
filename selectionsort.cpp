# include<iostream>
using namespace std;
int  main()
{
 int a[10],size,i,j;
 cout<<"enter the size of array:";
 cin>>size;
 cout<<"enter the elements into array:\n";
 for(i=0;i<=size;i++)
 {
     cin>>a[i];
 }
 cout<<"array before sorting:\n";
 for(i=0;i<=size;i++)
 {
     cout<<a[i]<<" ";
 }
 cout<<"\narray after sorting using selection sort:\n";
 for(i=0;i<=size;i++)
 {
 int min=i;
 for (j=i+1;j<=size;j++)
 {
     if(a[j]<a[min])
     {
         min=j;
     }
 }
 if(min!=i)
 {
 int temp=a[min];
 a[min]=a[i];
 a[i]=temp; 
 }     
 }
 for(i=0;i<=size;i++)
 {
     cout<<a[i]<<" ";
 }
    return 0;
}