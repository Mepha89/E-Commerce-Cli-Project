// CLI based e-coommerece
#ifndef CART_H
#define CART_H
#include <iostream>
using namespace std;
#include <string>
#include<sstream>

template <class T, class T2>
class Node
{
public:
    int ItemID;
    string name;
    T price;
    T2 quantity;
    string expiry;
    string catagory;
    Node* next;
    string date;
    Node* prev;
    // Node(int data)
    // {
    //     Node*new_node=new Node();
    //     new_node->data=data;
    // }oxen
    // print Cart
    void printList (Node* n)
    {
        int i=1;
        while (n != NULL ) 
        {
            cout << i << " : " << " | " << n->ItemID << " | " << n->name << " | " << n->price << " | " << n->quantity << " | " << n->date << " | " << endl;
            n = n->next;
            i++;
        }
    } 
    //Used to push to linked list
    void push(Node** head_ref, int ItemId, string name, string catagory, T price, T2 quantity, string date)
    {
        if (*head_ref==NULL)
        {
            Node* head_node=new Node();
           // head_node->name=customer_ID
           head_node->name=name;
           head_node->quantity=quantity;
           head_node->ItemID = ItemId;
           head_node->catagory = catagory;
           head_node->date = date;
           head_node->next=NULL;
           head_node->price=price;
           *head_ref=head_node;
        }
        else
        {
            /* 1. allocate node*/
            Node* new_node = new Node();
            /* 2. put in the data*/
            new_node->quantity = quantity;
            new_node->ItemID = ItemId;
            new_node->catagory = catagory;
            new_node->name = name;
            new_node->price = price;
            /* 3. Make next of new node as head
            and previous as NULL*/
            new_node->next = (*head_ref);
            new_node->prev = NULL;
            /* 4. change prev of head node to new node*/
            if ((*head_ref) != NULL)
                (*head_ref)->prev = new_node;
            /* 5. move the head to point to the new node*/
            (*head_ref) = new_node;
        }
    }
    Node* newNodestack(string name,int quantity)
    {
        Node* stackNode = new Node();
        stackNode->name = name;
        stackNode->quantity=quantity;
        stackNode->next = NULL;
        return stackNode;
    }
    //Used to push to stack
    void stackpush(Node* root, string name,int quantity)
    {

	    Node* stackNode = newNodestack(name,quantity);
	    stackNode->next = root;
	    root = stackNode;
	    cout<< name<<" : "<<quantity<< " pushed to stack\n";
    }
    //Used to pop items off stack
    Node pop(Node** root)
    {   
	    if (*root==NULL)
        {
            cout<<"History is empty"<<endl;
        }
	    Node* temp = *root;
	    *root = (*root)->next;
	    // string name = temp->name;
        // int quantity=temp->quantity;
	    // free(temp);
	    // cout<<"|"<<name<<" : "<<quantity<<"|"<<endl;
        return *temp;
    }
    //peeking into the stack of checked-out items
    void peek(Node* root)
    {   
        if (root==NULL)
        {
            cout<<"History is empty"<<endl;
        }
        cout<<root->data<<endl;
    }
    // add checked-out items to order stack
    void addHistory(Node **root, Node**head_ref)
    {
        Node*current=*head_ref;
        Node* root1= *root;
        while(current!=NULL)
        {
           stackpush(root1,current->name,current->quantity);
            current=current->next;
        }
    }
    //Converts stack of ordered items to string to be used to push to another stack containing UserID:History
    //Need customer ID to implement fully
    string stackTostring(Node **root)
    {
        Node*count=*root;
        int j=1;
        stringstream ss;
        string quantity;
        string price;
        string items;
        while(count!=NULL)
        {
            count=count->next;
            j++;
        }
        while(*root!=NULL)
        {
            for(int i=0;i<j;i++)
            {
                Node popped=pop(root);
                ss<<popped.quantity;
                ss>>quantity;
                ss<<popped.price;
                ss>>price;
                items=items+("|"+popped.name+" : "+quantity+" : $ "+price+"|");
            }
        
        }
        return items;
    }
    //To be changed later to delete specific items off cart
    void deleteNode(Node** headnode,string name)
    {
        Node *current=*headnode;
        Node *prev=NULL;
        if(current==NULL)
        {
            cout<<"List is empty!"<<endl;

        }
        if (current!=NULL)
        {
            if (current->name==name)
            {   
                if(current->next!=NULL)
                {
                    (*headnode)=current->next;
                    current=current->next;
                }
                else
                    (*headnode)=NULL;
                    current=NULL;
            }

        }
        while(current!=NULL )
        {
            if (current->name==name)
                {
                    prev=current->prev;
                    prev->next=current->next;
                    if (current->next==NULL)
                    {
                        current=NULL;
                        break;
                    }
                    current->next->prev=prev;
                    break;
                    
                }
                current=current->next;
            if(current==NULL)
            {
                    cout<<endl<<"Item doesn't exit"<<endl;
            }
        }   

        return;
    }
    //Clear whole cart
    void clearList(Node**headnode)
    {
       
        while ((*headnode) != NULL)
        {
            Node* next = (*headnode);
            (*headnode) = (*headnode)->next;
            free(next);
            

        }
    }
    //Get caart total
    void getTotal(Node **headref)
    {
        int price=0;
        Node *current=*headref;
        if (current==NULL)
        {
            cout<<"Cart is empty! please add some items to total."<<endl;;
        }
        else if ( current!= NULL)
        {
            while (current!=NULL)
            {
                price+=(current->price*current->quantity);
                current=current->next;
            }
        }
        cout<<"The total cost of the current cart is: "<<price<<" ."<<endl;
    }
    //Checkout
    //needs to be changed to implement with customer ID
void Checkout(Node**headref)
    {
       // Node*current=*headref;
       ///* cout<<"Items being checked out: "<<endl;*/
       // int index=0;
       // while(current!=NULL)
       // {   
       //     index+=1;
       //     cout<<index<<" : "" | " << current->ItemID << " | " << current->name << " | " << current->price << " | " << current->quantity << " | " << current->date << " | "<< endl;
       //     current=current->next;

       // }
        getTotal(headref);
        //char decision;
        //cout<<"Are yous sure you want to buy the listed items?(y/n)";
        //cin >>decision;
        //if (decision=='n')
        //{
        //   
        //}
        //else
        //{
        //    //update customer history of order
        //    //createCustomerHist(cusID,headref)
        //    //updateINV(headref)
        //    //clear cart
        //    // addHistory(root,headref);
        //    //addHistory(root,headref);
        //    clearList(*headref);

        //}
    }
    
    
    
};
#endif

