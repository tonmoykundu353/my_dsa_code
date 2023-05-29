
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
int find_length(node *temp)
{
    int count=0;
    while(temp!=nullptr)
    {
        count++;
        temp=temp->link;
    }
    return count;
}
void rotate_right(node **head,int k)
{
    if(k==0 || *head==nullptr || (*head)->link==nullptr)
        return;
    k=k%find_length(*head);
    if(k==0)
        return;
    while(k)
    {
        node *temp=*head;
        while(temp->link->link!=nullptr)
            temp=temp->link;
        temp->link->link=*head;
        *head=temp->link;
        temp->link=nullptr;
        k--;
    }
}
void rotate_left(node **head,int k)
{
    if(k==0 || *head==nullptr || (*head)->link==nullptr)
        return;
    k=k%find_length(*head);
    if(k==0)
        return;
    while(k)
    {
        node *temp=*head;
        while(temp->link!=nullptr)
            temp=temp->link;
        temp->link=*head;
        *head=(*head)->link;
        temp->link->link=nullptr;
        k--;
    }
}
int main()
{
    node *head1=nullptr;
    create(&head1);
    display(head1);
    rotate_right(&head1,3);
    display(head1);
    rotate_left(&head1,3);
    display(head1);
}

