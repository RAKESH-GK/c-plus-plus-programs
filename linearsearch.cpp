# include<iostream>
using namespace std;

class linearsearch
{
    char a[50], search;
    int flag=0,i,size;

    public:
    void getdata()
    {
      cout<<"enter the size of array:";
      cin>>size;
      cout<<"enter the values:\n";
      for(i=0;i<size;i++)
      {
          cin>>a[i];
      }
    }
    void searchdata()
    {
        cout<<"enter search element in array:";
        cin>>search;
        for(i=0;i<size;i++)
        {
            if(a[i]==search)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"search is successfull";
        }
        else
        {
            cout<<"search is unsuccesfull";
        }
    }
};

int main()
{
    linearsearch l;
    l.getdata();
    l.searchdata();
    return 0;
}
/*
OUTPUT:
enter the size of array:4
enter the values:
w
e
r
t
enter search element in array:g
search is unsuccesfull
*/
