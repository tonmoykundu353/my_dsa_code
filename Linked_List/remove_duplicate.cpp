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
    for(int i=0; i<n; i++)
    {
        cin>>data;
        creation(head,data); /// catch
    }
}
void remove_duplicate(node *head)
{
    if(head==nullptr || head->link==nullptr)
        return;
    node *ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1!=nullptr && ptr1->link!=nullptr)
    {
        ptr2=ptr1;
        while(ptr2->link!=nullptr)
        {
            if(ptr1->data==ptr2->link->data)
            {
                dup=ptr2->link;
                ptr2->link=ptr2->link->link;
                delete dup;
            }
            else
                ptr2=ptr2->link;

        }
        ptr1=ptr1->link;
    }
}
int main()
{
    node *head=nullptr;
    create(&head);
    display(head);
    remove_duplicate(head);
    display(head);

    return 0;
}

