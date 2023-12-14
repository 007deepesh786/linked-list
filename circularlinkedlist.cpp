#include<iostream>
#include<map>
using namespace std;

class Node{
    public:

    int data;
    Node*next;
    Node(int d){
        this -> data =d;
        this -> next =NULL;
    }
    ~Node(){
         int value = this ->data;
       if(this->next != NULL){
        delete next;
        this ->next = NULL;
       }
       cout << "memory is free for the node with data" << endl;

    }

};
void insertnode(Node*&tail , int element , int d){
    // Assuming that element is present in the list

    // empty list
    if(tail == NULL){
           Node*newnode=new Node(d);
           tail=newnode;
           newnode -> next = newnode;

    }
    else{
        Node*curr = tail;
        while(curr->data != element){
             curr = curr->next;
        }
        // current found = and current is representing element wala node;
        Node*temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp; 
    }

}
void print(Node*tail){
    Node*temp = tail;
    do{
        cout << tail -> data << " ";
        tail = tail->next;
    }while(tail!=temp);
    cout << endl;

}
// deletion
void deletion(Node*&tail, int val){
     if(tail == NULL){
        return;
     }

     Node*prev = tail;
     Node*curr = prev -> next;
     while(curr -> data != val){
        prev = curr;
        curr = curr->next;

     }
     prev -> next = curr ->next;
     if(tail == curr){
        tail = prev;
     }

    //  FOR ONE  NODE LINKED LIST
     if(curr == prev){
        tail=NULL;
     }
     curr -> next = NULL;

     delete curr;
}
Node* floyddetectloop(Node*head){

    if(head == NULL){
        return NULL;
    }

    Node*slow=head;
    Node*fast =head;

     while(slow != NULL && fast != NULL){
        fast = fast -> next;
        
        if(fast != NULL ){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
     }
     return NULL;
}
Node*getstartingnode(Node*head){
    if(head == NULL){
        return NULL;
    }

   Node*intersection=floyddetectloop(head);

    Node*slow=head;
    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection->next;
    }
        return slow;
}
Node *removeLoop(Node *head)
{
    if(head == NULL)
     return NULL;

     Node*startofloop = getstartingnode(head);
     Node*temp=startofloop;
     while(temp->next != startofloop){
         temp = temp->next;
     }
     temp->next=NULL;
     return head;
}
int main(){
    
    Node*tail =NULL;
    // Node*head = NULL;
    
    insertnode(tail , 3,4);
    // print(tail);

insertnode(tail , 4,5);
    // print(tail);

    insertnode(tail , 5,6);
    // print(tail);

    insertnode(tail , 6,17);
    // print(tail);
    // deletion(tail,17);
    // print (tail);

   if(floyddetectloop(tail) != NULL)
   cout << "cycle "<< endl;

   else{
    cout << "no cycle " << endl;
   }
  cout <<  getstartingnode(tail) << endl;

    return 0;
}