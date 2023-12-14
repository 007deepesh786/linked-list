#include<iostream>
using namespace std;
//  Node class
// class Node{
//     public:
//     int node;
//     Node*next;
//      Node(int node){
//     this -> node = node;
//     this -> next = NULL; 
// }
// };
// void insertnode(Node*&head,int d){
//     Node*temp =new Node(d);
//     temp -> next = head;
//     head = temp;


// }
// void print(Node* &head){
//   Node*temp=head;
//   while(temp!=head){
//     cout << temp->next << endl;
//     temp = temp -> next;
//   }
// }

// int main(){
// Node*node1=new Node(10);

// cout << node1 -> node << endl;
// cout << node1 -> next << endl;


// }

// singly linked list // (insert at head) // (insert at tail) //(insert at any position)// Deletion
class Node{
    public:
    int node;
    Node*next;
    // constructor
     Node(int node){
    this -> node = node;
    this -> next = NULL; 
     }

    // Destructors
   ~Node () { 
       int value = this ->node;
       if(this->next != NULL){
        delete next;
        this ->next = NULL;
       }
       cout << "memory is free for the node with data" << endl;

    }

};
void insertathead(Node*&head,int d){
    Node*temp =new Node(d);
    temp -> next = head;
    head = temp;
}
void insertattail(Node*&tail,int d){
    Node*temp =new Node(d);
    tail -> next = temp;
    tail = tail -> next;

}
void insertatposition(Node*&tail,Node*&head,int position,int d){
    Node*temp =head;
    int cnt=1;

    // for first position
    if(position == 1){
        insertathead(head,d);
        return;
    }

    
    while(cnt < position-1){
      temp = temp-> next;
      cnt++;
    }

    //  to put tail at a last position
    if(temp -> next == NULL){
        insertattail(tail,d);
        return;
    }


    Node*nodetoinsert =new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
}
// for deletion of node
void deletion(int position , Node*&head){
  if(position == 1){
     Node*temp=head;
     head = head -> next;
     temp -> next =NULL;
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

void print(Node* &head){
  Node*temp=head;
  while(temp!=NULL){
    cout << temp->node <<" ";
    temp = temp -> next;
  }
  cout << endl;
}
int main(){
Node*node1=new Node(10);

// head pointed to node1

Node*head=node1;
Node*tail=node1;

print(head);
insertathead(head,12);
print(head);
insertathead(head,13);
print(head);
insertatposition(tail,head,1,22);
print (head);
deletion(1,head);
print(head);

return 0;

}



