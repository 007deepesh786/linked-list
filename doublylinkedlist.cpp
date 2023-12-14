#include<iostream>
using namespace std;
class Node{
   public:
   int data;

   Node*prev;
   Node*next;

    // constructor 

    Node(int d){
        this -> data =d;
        this -> prev = NULL;
        this -> next = NULL;
    } 
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << val << endl;
    }  
    
};
// traversing a linked list
void print(Node*&head){
    Node*temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp -> next;
    }
}
// gives length to the linked list
int getlength(Node* head){
    int len=0;
     Node*temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
        
    }
    return len;
}
void insertathead(Node*&head , int d){
    Node*temp =new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
void insertattail(Node*&tail , int d){
    Node*temp =new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}
void insertatposition(Node*&tail,Node*&head,int position , int d){
    if(position == 1){
        insertathead(head,d);
        return;
    }
    Node*temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertattail(tail,d);
        return;
    }

    Node*nodetoinsert = new Node(d);

    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}
// for deletion of node
void deletion(int position , Node*&head){
  if(position == 1){
     Node*temp=head;
     temp->next->prev=NULL;
    head = temp->next;
    temp->next=NULL;
    delete temp;
  }
  else{
    Node*curr = head;
    Node*prev = NULL;

    int cnt =1;
    while(cnt < position){
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
  }

}
int main(){
  Node*node1 = new Node(10);
  Node*head=node1;
  Node*tail=node1;

  print(head);

  insertathead(head,11);
  print(head);

  insertathead(head,12);
  print(head);

  insertattail(tail,11);
  print(head);


 
  return 0;

}