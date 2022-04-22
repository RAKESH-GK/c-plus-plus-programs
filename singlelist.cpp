# include<iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};

node* head;

class linklist
{
    public:
    int ch,value,count,pos,search,ele,flag=0;
    node* newnode,*temp,*temp1;
    void createlist();
    void insertion();
    void deletion();
    void display();
    void searching();
};

int main()
{
    int choice;
    linklist l;
    while(1)
    {
        cout<<"\nMENU\n1. create\n2. insert\n3. delete\n4. display\n5. search\n6. exit\nenter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:l.createlist();
            break;
            case 2:l.insertion();
            break;
            case 3:l.deletion();
            break;
            case 4:l.display();
            break;
            case 5:l.searching();
            break;
            case 6: exit(0);
            default:cout<<"\ninvalid choice\n";
            break;
        }
    }
}

void linklist :: createlist()
{
    if(head==NULL)
    {
        newnode=new node;
        cout<<"enter the value:";
        cin>>value;
        newnode->data=value;
        newnode->link=NULL;
        head=newnode;
    }
    else
    {
        cout<<"\nlinklist already created\n";
    }
}

void linklist :: insertion()
{
    if(head==NULL)
    {
        cout<<"\nfirst create linklist\n";
    }
    else
    {
        newnode=new node;
        cout<<"enter value to insert:";
        cin>>value;
        newnode->data=value;
        newnode->link=NULL;
        cout<<"\nMENU\n1. insert at end\n2. insert at begining\n3. insert at position\nenter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            temp=head;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newnode;
            break;
            case 2:
            newnode->link=head;
            head=newnode;
            break;
            case 3:
            count=1;
            temp=head;
            while(temp->link!=NULL)
            {
                count++;
                temp=temp->link;
            }
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
                    newnode->link=head;
                    head=newnode; 
                }
                else if(pos==count)
                {
                    temp=head;
                    while(temp->link!=NULL)
                    {
                        temp=temp->link;
                    }
                    temp->link=newnode;
                }
                else
                {
                    temp=head;
                    for(int i=0;i<pos-1;i++)
                    {
                        temp=temp->link;
                    }
                    newnode->link=temp->link;
                    temp->link=newnode;
                }
            }
            break;
            default:cout<<"\ninvalid choice\n";
            break;
        }

    }
}

void linklist :: deletion()
{
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
        cout<<"\nMENU\n1. delete from end\n2. delete from begining\n3. delete from position\nenter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            if(head->link==NULL)
            {
                ele=head->data;
                head=NULL;
            }
            else
            {
                temp=head;
                while(temp->link!=NULL)
                {
                    temp1=temp;
                    temp=temp->link;
                }
                temp1->link=NULL;
                ele=temp->data;
                free(temp);
            }
            cout<<"\n"<<ele<<" is deleted\n";
            break;
            case 2:
            if(head->link==NULL)
            {
                ele=head->data;
                head=NULL;
            }
            else
            {
                temp=head;
                head=head->link;
                ele=temp->data;
                temp->link=NULL;
                free(temp);
            }
            cout<<"\n"<<ele<<" is deleted\n";
            break;
            case 3:
            count=0;
            temp=head;
            while(temp->link!=NULL)
            {
                count++;
                temp=temp->link;
            }
            cout<<"enter the position to delete:";
            cin>>pos;
            if(pos>count)
            {
                cout<<"\ninvalid position\n";
            }
            else
            {
                if(pos==0 && head->link==NULL)
                {
                    ele=head->data;
                    head=NULL;  
                }
                else if(pos==0)
                {
                    temp=head;
                    head=head->link;
                    ele=temp->data;
                    temp->link=NULL;
                    free(temp);
                }
                else if(pos==count)
                {
                    temp=head;
                    while(temp->link!=NULL)
                    {
                    temp1=temp;
                    temp=temp->link;
                    }
                    temp1->link=NULL;
                    ele=temp->data;
                    free(temp);
                }
                else
                {
                    temp=head;
                    for(int i=0;i<pos;i++)
                    {
                        temp1=temp;
                        temp=temp->link;
                    }
                    temp1->link=temp->link;
                    temp->link=NULL;
                    ele=temp->data;
                    free(temp);
                }
                cout<<"\n"<<ele<<" is deleted\n";
            }
            break;
        }
    }

}

void linklist :: display()
{
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
        cout<<"\nvalues in linklist are:\n";
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<"\n";
    }
}

void linklist :: searching()
{
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
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
            temp=temp->link;
        }
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

