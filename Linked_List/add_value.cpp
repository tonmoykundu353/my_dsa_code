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
    node *first,*second,*third;
    first=*head;
    second=third=nullptr;
    while(first!=nullptr)
    {
        third=second;
        second=first;
        first=first->link;
        second->link=third;
    }
    *head= second;
}
void add_value(node **head)
{
    reverse_link(&*head);
    int sum=0;
    int add=1;
    node *curr,*prev;
    curr=*head;
    prev=nullptr;
    while(curr!=nullptr)
    {
        sum=curr->data + add;
        add=sum/10;
        curr->data=sum%10;\
        prev=curr;
        curr=curr->link;
    }
    if(add!=0)
    {
        node *ptr=new node();
        ptr->data=add;
        ptr->link=nullptr;
        prev->link=ptr;
    }
    reverse_link(&*head);
}
int main()
{
    node *head=nullptr;
    create(&head);
    display(head);
    add_value(&head);
    display(head);
    return 0;
}

