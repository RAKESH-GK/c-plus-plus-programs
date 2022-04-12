# include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};

class linklist
{
    node* head;

    public:
    void insertend();
    void insertbegin();
    void insertposition();
    void display();
};

void linklist :: insertend()
{
    int value;
    node* newnode;
    node* temp;
    newnode=new node;
    cout<<"enter the value to insert:";
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

void linklist :: insertbegin()
{
    int value;
    node* newnode;
    newnode=new node;
    cout<<"enter the value to insert:";
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

void linklist :: insertposition()
{
    node* temp1,temp2,temp3,newnode;
    int count=0,pos,value;
    temp1=newnode;
    while(temp1->link!=NULL)
    {
        count++;
        temp1=temp1->link;
    }
    count++;
    cout<<"enter the position:";
    cin>>pos;
    if(pos>count)
    {
        cout<<"\ninvalid position\n";
    }
    else
    {
        newnode=new node;
        
    
    }

}

void linklist :: display()
{
node* temp;
temp=head;
if(head==NULL)
{
    cout<<"\nlist is empty\n";
}
else
{
cout<<"values in linked list are:\n";
while (temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->link;
}
}
}

int main()
{
    linklist l;
    int ch;
    while(1)
    {
        cout<<"\nMENU\n1. insert at end\n2.insert at begin \n2. display\n3. exit\nenter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
            l.insertend();
            break;
        case 2:
            l.insertbegin();
            break;
        case 3:
            l.display();
            break;
        case 4:
            exit(0);
        }
    }   
}