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
void sort_0_1_2(node **head)
{
    if(*head==nullptr || (*head)->link==nullptr)
        return ;
    node *zero_head=new node();
    node *one_head=new node();
    node *two_head=new node();

    node* zero_tail=zero_head;
    node* one_tail=one_head;
    node* two_tail=two_head;

    node *temp=*head;
    while(temp!=nullptr)
    {
        if(temp->data==0)
        {
            zero_tail->link=temp;
            zero_tail=temp; /// update
        }
        else if(temp->data==1)
        {
            one_tail->link=temp;
            one_tail=temp; /// update
        }
        else if(temp->data==2)
        {
            two_tail->link=temp;
            two_tail=temp; /// update
        }
        temp=temp->link;
    }

    zero_tail->link=nullptr;
    one_tail->link=nullptr;
    two_tail->link=nullptr;

    if(one_head->link==nullptr)
        zero_tail->link=two_head->link;
    else
    {
        zero_tail->link=one_head->link;
        one_tail->link=two_head->link;
    }
    *head=zero_head->link;
}
int main()
{
    node *head=nullptr;
    create(&head);
    display(head);
   sort_0_1_2(&head);
    display(head);
    return 0;
}
