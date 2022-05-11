# include<iostream>
using namespace std;
//creating structure
struct node
{
    int data;
    node *link;
};
//global declaration of last node
node *last;
//creating a class
class circular
{
    public:
    int ele,ch,count,pos;
    node *newnode,*temp,*temp1;

    void createlist()
    {
        if(last==NULL)
        {
            last=new node;
            cout<<"enter data to insert:";
            cin>>ele;
            last->data=ele;
            last->link=last;
            cout<<"\n"<<last->data<<" is inserted succesfully\n";
        }
        else
        {
            cout<<"\nlist already created\n";
        }
    }

    void insertion()
    {
        if(last==NULL)
        {
            cout<<"\nfisrt create linklist\n";
        }
        else
        {
        newnode=new node;
        cout<<"enter data to insert:";
        cin>>ele;
        newnode->data=ele;
        cout<<"\nCERCULAR LINKLIST INSERTION MENU\n1. insert at begin\n2. insert at end\n3. insert at position\nenter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            newnode->link=last->link;
            last->link=newnode;
            cout<<"\n"<<newnode->data<<" is inserted succesfully\n";
            break;

            case 2:
            newnode->link=last->link;
            last->link=newnode;
            last=newnode;
            cout<<"\n"<<newnode->data<<" is inserted succesfully\n";
            break;

            case 3:
            count=0;
            temp=last->link;
            do
            {
                count++;
                temp=temp->link;
            } while (temp!=last->link);
            cout<<"enter the position to insert:";
            cin>>pos;
            if(pos>count)
            {
                cout<<"\ninvalid position\n";
            }
            else
            {
                if(pos==0)
                {
                    newnode->link=last->link;
                    last->link=newnode;  
                }
                else if(pos==count)
                {
                    newnode->link=last->link;
                    last->link=newnode;
                    last=newnode;
                }
                else
                {
                    temp=last->link;
                    for(int i=0;i<pos-1;i++)
                    {
                        temp=temp->link;
                    }
                    newnode->link=temp->link;
                    temp->link=newnode;
                }
                cout<<"\n"<<newnode->data<<" is inserted succesfully\n";
            }
            break;

            default:cout<<"\ninvalid position\n";
            break;
        }
        }
    }

    void deletion()
    {
        if(last==NULL)
        {
            cout<<"\nlist is empty\n";
        }
        else
        {
            cout<<"\nCERCULAR LINKLIST DELETION MENU\n1. delete at begin\n2. delete at end\n3. delete at position\nenter your choice:";
            cin>>ch;
            switch(ch)
            {
                case 1:
                if(last->link==last)
                {
                    cout<<"\n"<<last->data<<" is deleted\n";
                    last=NULL;
                }
                else
                {
                    temp=last->link;
                    last->link=temp->link;
                    temp->link=NULL;
                    cout<<"\n"<<temp->data<<" is deleted\n";
                    free(temp);
                }
                break;

                case 2:
                if(last->link==last)
                {
                    cout<<"\n"<<last->data<<" is deleted\n";
                    last=NULL;
                }
                else
                {
                temp=temp->link;
                while(temp->link!=last)
                {
                    temp=temp->link;
                }
                temp->link=last->link;
                cout<<"\n"<<last->data<<" is deleted\n";
                free(last);
                last=temp;
                }
                break;

                case 3:
                count=-1;
                temp=last->link;
                do
                {
                    count++;
                    temp=temp->link;
                } while (temp!=last->link);
                cout<<"enter the position to delete:";
                cin>>pos;
                if(pos>count)
                {
                    cout<<"\ninvalid position\n";
                }
                else
                {
                    if(pos==0 && last->link==last)
                    {
                        cout<<"\n"<<last->data<<" is deleted\n";
                        last=NULL;
                    }
                    else if(pos==0)
                    {
                        temp=last->link;
                        last->link=temp->link;
                        temp->link=NULL;
                        cout<<"\n"<<temp->data<<" is deleted\n";
                        free(temp);
                    }
                    else if(pos==count)
                    {
                        temp=temp->link;
                        while(temp->link!=last)
                        {
                            temp=temp->link;
                        }
                        temp->link=last->link;
                        cout<<"\n"<<last->data<<" is deleted\n";
                        free(last);
                        last=temp;
                    }
                    else
                    {
                        temp=last->link;
                        for(int i=0;i<pos;i++)
                        {
                            temp1=temp;
                            temp=temp->link;
                        }
                        temp1->link=temp->link;
                        temp->link=NULL;
                        cout<<"\n"<<temp->data<<" is deleted\n";
                        free(temp);
                    }
                }
                break;

                default:cout<<"\ninvalid choice\n";
                break;
            }
        }

    }

    void display()
    {
        if(last==NULL)
        {
            cout<<"\nlist is empty\n";
        }
        else
        {
            cout<<"\ndata in circular linklist are:\n";
            temp=last->link;
            do
            {
                cout<<temp->data<<" ";
                temp=temp->link;
            } while (temp!=last->link);
            cout<<"\n";
        }

    }

    void searching()
    {
        int flag=0,value;
        if(last==NULL)
        {
            cout<<"\nlist is empty\n";
        }
        else
        {
            cout<<"enter the search element:";
            cin>>value;
            temp=last->link;
            do
            {
                if(value==temp->data)
                {
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                }
            }while (temp!=last->link);
            if(flag==1)
            {
                cout<<"\nsearch is succesfull\n";
            }
            else
            {
                cout<<"\nsearch is unsuccesfull\n";
            }
        }
    }
};

int main()
{
    system("cls");
    int choice;
    circular c;
    while(1)
    {
        cout<<"\nCIRCULAR LINKLIST MENU\n1. create list\n2. insert\n3. delete\n4. display\n5. search\n6. exit\nenter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:c.createlist();
            break;
            case 2:c.insertion();
            break;
            case 3:c.deletion();
            break;
            case 4:c.display();
            break;
            case 5:c.searching();
            break;
            case 6:exit(0);
            default:cout<<"\ninvalid choice\n";
            break;
        }
    }
    return 0;
}
