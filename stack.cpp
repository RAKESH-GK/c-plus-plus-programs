# include<iostream>
# define MAX 5
using namespace std;

class stackoperation
{
    public:
    int stack[MAX],ele,top=-1;
    void push()
    {
        if(top==MAX-1)
        {
            cout<<"\nstack is full\n";
        }
        else
        {
            cout<<"enter element to insert in stack:";
            cin>>ele;
            top++;
            stack[top]=ele;
        }

    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"\nstack is empty\n";
        }
        else
        {
            cout<<"\n"<<stack[top]<<" is poped from stack\n";
            top--;
        }

    }

    void display()
    {
        if(top==-1)
        {
            cout<<"\nstack is empty\n";
        }
        else
        {
            cout<<"\nelement in stack are:\n";
            for(int i=0;i<=top;i++)
            {
                cout<<stack[i]<<" ";
            }
            cout<<"\n";
        }
    }
};

int main()
{
    int ch;
    stackoperation stk;
    while(1)
    {
        cout<<"\nMENU\n1. push\n2. pop\n3. display\n4. exit\nenter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1: stk.push();
            break;
        case 2: stk.pop();
            break;
        case 3: stk.display();
            break;
        case 4: exit(0);
        default: cout<<"\ninvalid choice\n";
            break;
        }
    }
}