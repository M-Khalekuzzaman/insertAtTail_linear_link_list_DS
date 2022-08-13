#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;
    //Constructor declare
    Node(int data){
        this -> data = data;
        this -> Next = NULL;
    }
};
void insertAtHead(Node* &head,int data)
{
    //new node creation
    Node *new_node = new Node(data);
    //save previous head
    Node *save_previous_head = head;
    //new node point to save_previous_node
    new_node->Next = save_previous_head;
    //update head is new_node
    head = new_node;


}
void insertAtTail(Node* &head,int data)
{
   Node *newNode = new Node(data);
   if(head == NULL){
     head = newNode;
     return;
   }
   Node *temp = head;
   while(temp->Next != NULL){

        temp = temp->Next;
   }
   temp->Next = newNode;
}
void printLinkList(Node* &head)
{
    Node *currentNode = head;
    while(currentNode != NULL){
        cout<<currentNode->data<<" ";
        currentNode = currentNode->Next;
    }
    cout<<endl;
}
int countLength(Node* &head)
{
    int count = 0;
    Node *tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->Next;
    }

    return count;
}
void insertAtPosition(Node* &head,int data,int pos)
{
    Node *newNode = new Node(data);
    if(pos == 1){
        Node *save_previous = head;
        newNode->Next = save_previous;
        head = newNode;
        return;
    }
    pos--;
    Node *temp = head;
    for(int i = 1;i<pos;i++){
        temp = temp->Next;
    }
    Node *save = temp->Next;
    temp->Next = newNode;
    newNode->Next = save;
}
int main()
{
    Node *head = NULL;
    int value;
    int choice = 2;
    cout<<"Choice 1 : Insert at head"<<endl<<"Choice 2 : Insert at tail"<<endl<<"Choice 3 : Insert at any position"<<endl<<"Choice 0 : Exit"<<endl<<endl;
    while(choice != 0){
        cout<<"Enter your value :";
        cin>>value;
        if(choice == 1) insertAtHead(head,value);
        else if(choice == 2) insertAtTail(head,value);
        else if(choice == 3){
         int pos;
         cout<<"Enter your choose position :";
         cin>>pos;
         insertAtPosition(head,value,pos);
        }
        else return 0;
        cout<<"Next choice ";
        cin>>choice;
    }
    cout<<endl<<"Link List : ";
    printLinkList(head);
    int length = countLength(head);
    cout<<"Link list length "<<length<<endl;


    return 0;
}
