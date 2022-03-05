# include<iostream>
using namespace std;
class binarysearch
{
    int a[10],size,i,flag=0,m,ele,l,h;
    public:
    void getdata()
    {
        cout<<"enter the size of the array:";
        cin>>size;
        cout<<"enter values into array in asending order:\n";
        for(i=0;i<=size-1;i++)
        {
            cin>>a[i];
        }
    }
    void searchdata()
    {
        cout<<"enter the search element:";
        cin>>ele;
        l=0;
        h=size;
        while(l<=h)
        {
        m=l+h-1/2;
        if(m==ele)
        {
         flag=1;
         break;
        }
        else if(ele>m)
        {
        l=m+1;
        }
        else
        {
        h=m-1;
        }
        }
        if(flag==1)
        {
            cout<<"search is succesfull\nThe position is:"<<m-1;
        }
            else
            cout<<"search is unsuccesful";
    }
};

int main()
{
    binarysearch b;
    b.getdata();
    b.searchdata();
    return 0;
}