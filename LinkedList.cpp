#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node()
    {
        data=0;
    }
    node(int n)
    {
        data=n;
        next=nullptr;
    }
};

void show(node* head)
{
    node* temp=head;
    while(temp)
    {
        cout<< temp->data << " ";
        temp=temp->next;
    }
    cout<<endl;
}

node* invalue(vector<int>&v,node* head)
{
    cout<< "Inserting Value to Linked List from Vector\n";
    node* temp = head;
    node* mover = head;
    for(int i=0;i<v.size();i++)
    {
        node* temp = new node(v[i]);
        mover->next=temp;
        mover=temp;
    }
    node* t= head;
    head=t->next;
    delete t;
    return head;
}

node* pushfront(node* head,int n)
{
    cout<< "Inserting Value "<< n << " to head\n";
    node* newnode = new node(n);
    newnode->next= head;
    head=newnode;
    return head;
}

node* pushlast(node* head,int n)
{
    cout<< "Inserting Value "<< n << " to tail\n";
    node* newnode = new node(n);
    node* temp = head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

node* push_before_value(node* head,int n,int val)
{
    cout<< "Inserting Value "<< val << " before " << n<<endl;
    node* temp = head;
    while(temp->next->data!=n)
    {
        temp=temp->next;
    }
    node* newnode = new node(val);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node* push_after_value(node* head,int n,int val)
{
    cout<< "Inserting Value "<< val << " after " << n<<endl;
    node* temp = head;
    while(temp->data!=n)
    {
        temp=temp->next;
    }
    node* newnode = new node(val);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node* delfront(node* head)
{
    if(head==nullptr) return head;
    cout<< "Deleting Front\n";
    node* del = head;
    head=head->next;
    delete del;
    return head;
}

node* dellast(node* head)
{
    cout<< "Deleting Tail\n";
    node* temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    node* del=temp->next->next;
    temp->next=nullptr;
    delete del;
    return head;
}

node* delete_before_value(node* head,int n)
{
    cout<< "Deleting Value before " << n<<endl;
    if(head->data==n) return head;
    node* temp = head;
    node* prev = nullptr;
    while(temp->next->data!=n)
    {
        prev=temp;
        temp=temp->next;
    }
    node* del = temp;
    prev->next=temp->next;
    delete del;
    return head;
}

node* delete_after_value(node* head,int n)
{
    cout<< "Deleting Value after " << n<<endl;
    node* temp = head;
    node* prev = nullptr;
    while(temp->data!=n)
    {
        prev=temp;
        temp=temp->next;
    }
    if(!temp->next) return head;
    node* del = temp->next;
    temp->next=temp->next->next;
    delete del;
    return head;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9};

    node* head = new node();
    head=invalue(v,head);
    show(head);
    head=pushfront(head,5);
    show(head);
    head=pushlast(head,5);
    show(head);
    head=push_before_value(head,5,50);
    show(head);
    head=push_after_value(head,5,50);
    show(head);
    head=delfront(head);
    show(head);
    head=dellast(head);
    show(head);
    head=delete_before_value(head,2);
    show(head);
    head=delete_after_value(head,6);
    show(head);
}
