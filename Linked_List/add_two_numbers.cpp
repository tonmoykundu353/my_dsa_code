
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    node *link;
    int data;
};
void creation(node **head,int data)
{
    node *ptr=new node();
    ptr->data=data;
    ptr->link=nullptr;
    if(*head==nullptr)
        *head=ptr;
    else
    {
        node *temp=*head;
        while(temp->link!=nullptr)
            temp=temp->link;
        temp->link=ptr;
    }
}
void display(node *temp)
{
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
void create(node **head)
{
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        creation(head,data); /// catch
    }
}
void reverse_link(node **head)
{
    node*first,*second,*third;
    first=*head;
    second=third=nullptr;
    while(first!=nullptr)
    {
        third=second;
        second=first;
        first=first->link;
        second->link=third;
    }
    *head=second;
}
node *add_two_numbers(node *first,node *second)
{
    reverse_link(&first);
    reverse_link(&second);
   node* third=new node();
   node *temp=third;
   int carry=0;
   while(first!=nullptr || second!=nullptr || carry!=0)
   {
       int x=0;
       if(first!=nullptr)
       {
           x=first->data;
           first=first->link;
       }
        int y=0;
       if(second!=nullptr)
       {
           y=second->data;
           second=second->link;
       }
       int sum=x+y+carry;
       carry=sum/10;
       sum=sum%10;
       node *newnode=new node();
       newnode->data=sum;
       newnode->link=nullptr;
       temp->link=newnode;
       temp=newnode;
   }
   third=third->link;
   reverse_link(&third);
   return third;
}
int main()
{
    node *head1=nullptr;
    create(&head1);
    display(head1);
        node *head2=nullptr;
    create(&head2);
    display(head2);
   node *head3= add_two_numbers(head1,head2);
   display(head3);


}
