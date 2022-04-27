# include<iostream>
using namespace std;

void mergearray(int a1[],int a2[],int a3[],int a4[],int n1,int n2,int n3)
{
    int i,j,k,l;
    i=j=k=l=0;
    while(i<n1 && j<n2 && k<n3)
    {
        if(a1[i]<a2[j])
        {
            if(a1[i]<a3[k])
            {
                a4[l++]=a1[i++];
            }
            else
            {
                a4[l++]=a3[k++];
            }
        }
        else
        {
            if(a2[j]<a3[k])
            {
                 a4[l++]=a2[j++];
            }
            else
            {
                a4[l++]=a3[k++];
            }
        }
    }
    while(i<n1)
    {
        a4[l++]=a1[i++];
    }
    while(j<n2)
    {
        a4[l++]=a2[j++];
    }
    while(k<n3)
    {
        a4[l++]=a3[k++];
    }

}
int main()
{
    int a1[]={10,20,30,40};
    int a2[]={41,51,61,71};
    int a3[]={90,80};
    int n1=sizeof(a1)/sizeof(a1[0]);
    int n2=sizeof(a2)/sizeof(a2[0]);
    int n3=sizeof(a3)/sizeof(a3[0]);
    int a4[n1+n2+n3];
    mergearray(a1,a2,a3,a4,n1,n2,n3);
    cout<<"\narray after merge:\n";
    for(int i=0;i<n1+n2+n3;i++)
    {
        cout<<a4[i]<<" ";
    }
    return 0;
}