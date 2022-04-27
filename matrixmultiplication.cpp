# include<iostream>
using namespace std;
int main()
{
    int m,n,i,j,k,m1,n1;
    cout<<"enter size for first matrix:\nrow:";
    cin>>m;
    cout<<"column:";
    cin>>n;
    int a[m][n];
    cout<<"enter values for first matrix:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"enter size for second matrix:\nrow:";
    cin>>m1;
    cout<<"column:";
    cin>>n1;
    int b[m1][n1];
    cout<<"enter values for second matrix:\n";
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            cin>>b[i][j];
        }
    }

    cout<<"\nvalues in first matrix:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nvalues in second matrix:\n";
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }

    if(n!=m1)
    {
        cout<<"\nmultiplication not posible\n";
    }
    else
    {
        int mult[m][n1];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n1;j++)
            {
                mult[i][j]=0;
                for(k=0;k<m1;k++)
                {
                mult[i][j]=mult[i][j]+a[i][k]*b[k][j];
                }
            }  
        }
        cout<<"\nvalues after multiplication:\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n1;j++)
            {
            cout<<mult[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}