#include<iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};

node* head;

class doublylist
{
    public:
    node *newnode,*temp,*temp1;
    int value,search,flag,ch,count,pos,ele;
    void createlist();
    void insertion();
    void deletion();
    void display();
    void searching();
};

int main()
{
    system("cls");
    doublylist dl;
    int choice;
    while (1)
    {
        cout<<"\nMENU\n1. create doublylinklist\n2. insert\n3. delete\n4. display\n5. search\n6. exit\nenter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:dl.createlist();
            break;
            case 2:dl.insertion();
            break;
            case 3:dl.deletion();
            break;
            case 4:dl.display();
            break;
            case 5:dl.searching();
            break;
            case 6:exit(0);
            default:cout<<"\ninvalid choice\n";
            break;
        }
    } 
    return 0;  
}

void doublylist :: createlist()
{
    if(head==NULL)
    {
    newnode=new node;
    cout<<"enter value:";
    cin>>value;
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    head=newnode;
    cout<<"\nlist is succesfully created and "<<value<<" is inserted\n";
    }
    else
    {
    cout<<"\nlist is already created\n";
    }   
}

void doublylist :: insertion()
{
    if(head==NULL)
    {
        cout<<"\ncreate a list first\n";
    }
    else
    {
        newnode=new node;
        cout<<"enter data to insert:";
        cin>>value;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        cout<<"\nMENU\n1. insert at end\n2. insert at begining\n3. insert at position\nenter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            newnode->prev=temp;
            temp->next=newnode;
            cout<<"\n"<<value<<" is succesfully inserted\n";
            break;

            case 2:
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            cout<<"\n"<<value<<" is succesfully inserted\n";
            break;

            case 3:
            count=0;
            temp=head;
            while(temp!=NULL)
            {
                count++;
                temp=temp->next;
            }
            cout<<"enter the position:";
            cin>>pos;
            if(pos>count)
            {
                cout<<"\ninvalid position\n";
            }
            else
            {
            if(pos==0)
            {
                newnode->next=head;
                head->prev=newnode;
                head=newnode;
            }
            else if(pos==count)
            {
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
            }
            else
            {
                temp=head;
                for(int i=0;i<pos;i++)
                {
                    temp1=temp;
                    temp=temp->next;
                }
                newnode->next=temp;
                temp->prev=newnode;
                newnode->prev=temp1;
                temp1->next=newnode;
            }
            cout<<"\n"<<value<<" is succesfully inserted\n";
            }
            break;
            default:cout<<"\ninvalid choice\n";
            break;
        }
    }
}

void doublylist :: deletion()
{
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
        cout<<"\nMENU\n1. delete from end\n2. delete from begining\n3. delete from position\nenter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
        if(head->next==NULL)
        {
            ele=head->data;
            head=NULL;
        }
        else
        {
            temp=head;
            while(temp->next==NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
            ele=temp->data;
            temp1->next=NULL;
            free(temp);
        }
        cout<<"\n"<<ele<<" is deleted succesfully\n";
        break;

        case 2:
        if(head->next==NULL)
        {
            ele=head->data;
            head=NULL;
        }
        else
        {
            temp=head;
            head=head->next;
            head->prev=NULL;
            ele=temp->data;
            free(temp);
        }
        cout<<"\n"<<ele<<" is deleted succesfully\n";
        break;

        case 3:
        count=0;
        temp=head;
        while(temp->next!=NULL)
        {
            count++;
            temp=temp->next;
        }
        cout<<"enter the position to delete:";
        cin>>pos;
        if(pos>count)
        {
            cout<<"\ninvalid position\n";
        }    
        else
        {
            if(pos==0 && head->next==NULL)
            {
                ele=head->data;
                head=NULL;
            }
            else if(pos==0)
            {
                temp=head;
                head=head->next;
                head->prev=NULL;
                ele=temp->data;
                free(temp);
            }
            else if(pos==count)
            {
                temp=head;
                while(temp->next!=NULL)
                {
                    temp1=temp;
                    temp=temp->next;
                }
                ele=temp->data;
                temp1->next=NULL;
                free(temp);
            }
            else
            {
                temp=head;
                for(int i=0;i<pos;i++)
                {
                    temp1=temp;
                    temp=temp->next;
                }
                temp1->next=temp->next;
                temp->next->prev=temp1;
                ele=temp->data;
                free(temp);
            }
            cout<<"\n"<<ele<<" is deleted succesfully\n";
        }
        break;
        
        default:cout<<"\ninvalid choice\n";
        break;
        }
    }
}

void doublylist :: display()
{
    if(head==NULL)
    {
        cout<<"\nlist in empty\n";
    }
    else
    {
        cout<<"\nvalues in list are:\n";
        temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        } 
        cout<<"\n"; 
    }     
}

void doublylist :: searching()
{
    if(head==NULL)
    {
        cout<<"\nlist in empty\n";
    }
    else
    {
        cout<<"enter the search element:";
        cin>>search;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==search)
            {
                flag=1;
                break;
            }
            else
            {
                flag=0;
            }
            temp=temp->next;
        }
        if(flag==1)
        {
            cout<<"\nserach is succesfull\n";
        }
        else
        {
            cout<<"\nsearch is unsuccesfull\n";
        }
    }
}

