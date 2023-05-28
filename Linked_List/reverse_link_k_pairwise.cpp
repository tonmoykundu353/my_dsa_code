
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
node* reverse_link_k_pairwise(node **head,int k)
{
    if(*head==nullptr)
        return nullptr;
    int x=k;
    int count=0;
    node *temp=*head;
    while(x>0 && temp!=nullptr)
    {
        temp=temp->link;
        x--;
    }
    if(x==0)
    {
    node*next,*prev,*curr;
    curr=*head;
    next=prev=nullptr;
    while(count<k)
    {
        next=curr->link;
        curr->link=prev; /// link swap
        prev=curr;
        curr=next;
        count++;
    }
    (*head)->link=reverse_link_k_pairwise(&next,k);
    return prev;
    }
    else
        return *head;

}
int main()
{
    node *head=nullptr;
    create(&head);
    display(head);
   head= reverse_link_k_pairwise(&head,3);
    display(head);
    return 0;
}
