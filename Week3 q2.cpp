#include<iostream>
using namespace std;
//making the link
class Node{
    //public data
    public:
    int data;
    //pointer to the next node
    Node* next;
    //constructor that points to the next element
    Node(int val){
     next = NULL;
     data = val;
     }
};

class Circularll{
    public:
    //pointer to the first element
    Node* head;
    //constructor to out it null;
    CircularLL(){
        head = NULL;
    }


    int Insert(int val){
        //creating a new node
        //temp->data = val;
        Node*temp = new Node(val);
        //check if the list is empty
        if(head == NULL){
            head = temp;
        }
        //in case the list isn't empty
        else{
            //temporary pointer
            Node* current  = head;
            while(current->next != head){
                current = current->next;
            }
            //link the new node
            temp->next = head;
            //then link the current to the new
            current->next = temp;
        }
    }
    int CountItems(){
        //temporary pointer
            Node* counter  = head;
        int i=1;
        while(counter->next != head ){
            counter = counter->next;
            i++;
        }
        return i+1;
    }

    void display(){
     //temporary pointer
        Node* current  = head;
        while(current->next != head){
            current = current->next;
            cout<< current->data << "->" ;
        }
        //ptinting the last element
        cout<< (current->next)->data << "->" <<endl;
        cout<< "NULL"<<endl;
    }

    void InsertAt(int val, int pos){

        //creating a new node
        //temp->data = val;
        Node*temp = new Node(val);
         //move the pointer to the new node
        //in case of empty list
        if(head == NULL){
            head = temp;
        }
        //in case the list is not empty
        else{
         //temporary pointer
            Node* current  = head;
         //moving to the pos
         int i=1;
         while( i < pos){
            current = current->next;
         }
        temp->next = current->next;
        current->next = temp;
        }
    }

    void Delete(){
        //in case of empty list
        if(head == NULL){
            delete head;
        }
        //in case the list is not empty
        else{
             //temporary pointer
            Node* current  = head;
            while(current->next != head){
                current = current->next;
            }
            //storing the last element
             Node*temp = current->next;
             //cutting the link
            current->next = head;
            //deleting
            delete temp;
        }
    }

    void DeleteAt(int pos){
        //temporary pointer
            Node* current  = head;
         //moving to the pos
         int i=1;
         while( i < pos){
            current = current->next;
         }
        //storing the last element
             Node*temp = current->next;
        //cutting the link
        current->next = temp->next;
        //deletng
        delete temp;
    }
};

int main(){
    Circularll csll1;
    for(int i= 1; i < 11; i++){
       csll1.Insert(i);
    }
    csl11.display();



    int x,y;
    cout<< "please enter the position at which you want to insert and the elements you want to insert respectively: "<<endl;
    cin>>y;
    cin>>x;
    int a = csl11.CountItems();
    cout<< a <<endl;
    if(y<=a){
        csl1.InsertAt(y,x);
    }
    else  cout<<"Linked List does not have that many elements "<<endl;
    csll1.display();

    csl1.Delete();
    csl1.display();
    cout<< "The number of items in your list is " <<csll1.CountItems()<<endl;
    cout<< "Please enter the position at which you want to delete the element at: "<<endl;
    int z;
    cin>> z;
    if(z<=a){
        csl1.DeleteAt(z);
    }
    else  cout<<"Linked List does not have that many elements "<<endl;
    csl1.display();
}



