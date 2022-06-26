# include<bits/stdc++.h>
using namespace std;

const int n=10;

int stk[n],top=-1,ele;

void push(int item)
{
top++;
stk[top]=item;
}

int pop()
{
ele=stk[top];
top--;
return ele;
}

int main()
{
string s;
int item;
cout<<"enter postfix expression:";
cin>>s;
for(int i=0;i<s.size();i++)
{
if(s[i]>='0' && s[i]<='9')
{
item=s[i]-48;
}
else
{
int s1=pop();
int s2=pop();
switch(s[i])
{
case '+':item=s2+s1;
break;
case '-':item=s2-s1;
break;
case '*':item=s2*s1;
break;
case '/':item=s2/s1;
break;
case '%':item=s2%s1;
break;
case '$':item=pow(s2,s1);
break;
default:
break;
}
}
push(item);
}
cout<<"after evaluation:"<<pop()<<"\n";
}
