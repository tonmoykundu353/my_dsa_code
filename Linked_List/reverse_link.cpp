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
int main()
{
    node *head=nullptr;
    create(&head);
    display(head);
    reverse_link(&head);
    display(head);
}
