# include<iostream>
# define MAX 5
using namespace std;

class queueoperation
{
    public:
    int queue[MAX],front=-1,rear=-1,ele;
    void insertion()
    {
        if(rear==MAX-1)
        {
            cout<<"\nqueue is full\n";
        }
        else
        {
            cout<<"enter element to insert in queue:";
            cin>>ele;
            rear++;
            queue[rear]=ele;
            if(front==-1)
            {
                front++;
            }
        }
    }

    void deletion()
    {
        if(rear==-1 || front>rear)
        {
            cout<<"\nqueue is empty\n";
        }
        else
        {
            cout<<queue[front]<<" is deleted\n";
            front++;
        }
    }

    void display()
    {
        if(rear==-1 || front>rear)
        {
            cout<<"\nqueue is empty\n";
        }
        else
        {   
            cout<<"\nelement in queue are:\n";
            for(int i=front;i<=rear;i++)
            {
                cout<<queue[i]<<" ";
            }
            cout<<"\n";
        }
    }
};

int main()
{
    int ch;
    queueoperation que;
    while(1)
    {
        cout<<"\nMENU\n1. insertion\n2. deletion\n3. display\n4. exit\nenter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:que.insertion();
            break;
        case 2:que.deletion();
            break;
        case 3:que.display();
            break;
        case 4:exit(0);
        default:cout<<"\ninvalid choice\n";
            break;
        }
    }
}