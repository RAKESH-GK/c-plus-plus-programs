#include<iostream>
using namespace std;

//defining structure
struct node
{
    int data;
    node* link;
};

//global declaration of head node
node* head;

//declaration of class
class linklist
{
    public:
    int value,count,pos,ele,ch,search,flag;
    node* newnode,*temp,*temp1,*temp2;
    void insertion();
    void deletion();
    void display();
    void searching();
    void insertend();
    void insertbegin();
    void insertposition();
    void deleteend();
    void deletefront();
    void deleteposition();
};

//main starts here
int main()
{
    linklist l;
    int choice;
    while (1)
    {
        cout<<"\nMENU\n1. insert\n2. delete\n3. display\n4. search\n5. exit\nenter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:l.insertion();
            break;
        case 2:l.deletion();
            break;
        case 3:l.display();
            break;
        case 4:l.searching();
            break;
        case 5:exit(0);
        default:cout<<"\ninvalid choice\n";
            break;
        }
    }  
}

//display the linked list
void linklist :: display()
{
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
    temp=head;
    cout<<"\nvalues in linked list are:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<"\n";
    }
}

//insert operations on linked list
void linklist :: insertion()
{
    cout<<"\nMENU\n1. insert at end\n2. insert at begining\n3. insert at position\nenter your choice:";
    cin>>ch;
    switch (ch)
    {
    case 1:insertend();
        break;
    case 2:insertbegin();
        break;
    case 3:insertposition();
        break;
    default: cout<<"\ninvalid input\n";
        break;
    }
}

//delete operations on linked list
void linklist :: deletion()
{
    cout<<"\nMENU\n1. delete from end\n2. delete from front\n3. delete from position\nenter your choice:";
    cin>>ch;
    switch (ch)
    {
    case 1:deleteend();
        break;
    case 2:deletefront();
        break;
    case 3:deleteposition();
        break;
    default: cout<<"\ninvalid input\n";
        break;
    }
}

//searching in linked list
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

//insert at end of node
void linklist :: insertend()
{
    newnode=new node;
    cout<<"enter value to insert:";
    cin>>value;
    newnode->data=value;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
    }
}

//insert at begining of node
void linklist :: insertbegin()
{
    newnode=new node;
    cout<<"enter value to insert:";
    cin>>value;
    newnode->data=value;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
}

//insert at specific position
void linklist :: insertposition()
{
    count=0;
    temp=head;
    while (temp!=NULL)
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
        newnode=new node;
        cout<<"enter the value to insert:";
        cin>>value;
        newnode->data=value;
        newnode->link=NULL;
        if (pos==0 && head==NULL)
        {
            newnode->link=head;
            head=newnode;
        }
        else if(pos==0)
        {
            newnode->link=head;
            head=newnode;
        }
        else if(pos==count)
        {
        temp=head;
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
        }
        else
        {
            temp=head;
            for(int i=0;i<pos;i++)
            {
                temp1=temp;
                temp=temp->link;
            }
            newnode->link=temp;
            temp1->link=newnode;
        }
    }  
}

//delete from end
void linklist :: deleteend()
{
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
    temp=head;
    while(temp->link!=NULL)
    {
        temp1=temp;
        temp=temp->link;
    }
    if(temp==head)
    {
        ele=temp->data;
        head=NULL;
    }
    else
    {
    ele=temp->data;
    temp1->link=NULL;
    free(temp);
    }
    cout<<"\n"<<ele<<" is deleted\n";
    }
}

//delete from front
void linklist :: deletefront()
{
     if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
        if(head->link==NULL)
        {
            ele=head->data;
            head=NULL;
        }
        else
        {
            temp=head;
            ele=temp->data;
            head=head->link;
            temp->link=NULL;
            free(temp);
        }
        cout<<"\n"<<ele<<" is deleted\n";
    }
}

//delete from specific position
void linklist :: deleteposition()
{
    count=-1;
    if(head==NULL)
    {
        cout<<"\nlist is empty\n";
    }
    else
    {
    temp=head;
    while (temp!=NULL)
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
        if (pos==0 && head->link==NULL)
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
        while (temp->link!=NULL)
        {
            temp1=temp;
            temp=temp->link;
        }
        ele=temp->data;
        temp1->link=NULL;
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
            temp2=temp->link;
            ele=temp->data;
            temp1->link=temp2;
            temp->link=NULL;
            free(temp);
        }
        cout<<"\n"<<ele<<" is deleted\n";
    }
    }  
}