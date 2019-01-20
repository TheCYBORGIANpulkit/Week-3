#include<iostream>
using namespace std;

class Node{
    public:
    //data
    int data;
    //pointer to the next node
    Node* next;
    Node* prev;
    //constructor taking the ptr to NULL

    Node(int val){
    //take the pointer
    next = NULL;
    prev = NULL;
    //taking value in the data
    data = val;
    }

};

class Doublell{
    //making everything public
    public:
     Node*head;
    //const taking pointer to the first element to NULl
    Doublell(){
        head = NULL;
    }

    void Insert(int val){
        //create a new node
        Node*temp = new Node(val);
        //move the pointer to the new node
        //in case of empty list
        if(head == NULL){
            head = temp;
        }
        //in case of non empty list
        else {
            //make a temporary pointer
            Node*current = head;
            while(current->next != NULL){
                current = current->next;
           }
            //link it with new node
            current->next = temp;
            //make the double link
            temp->prev = current;
        }

    }

    void InsertAt(int pos, int val){
        //create a new node
        Node* temp = new Node(val);

        //move the pointer to the new node
        //in case of empty list
        if(head == NULL){
            head = temp;
        }
        //in case the list is not empty
        else{
             //make a temporary pointer
            Node*current = head;

            int i=1;
            while(i<pos){
                current = current->next;
                i++;
            }
            //linking the new node to the pointer
            temp->next = current->next;
            //linking the pointer to the new node
            current->next = temp;
            //making double links
            (temp->next)->prev = temp;
            temp->prev = current;
        }
    }

    void Delete(){
        //make a temporary pointer
        Node*current = head;
        while(current->next != NULL){
            current = current->next;
        }
        //storing last element temporarily
        Node* temp = current;
        //cut the links
        (current->prev)->next = NULL;

        //delete the node
        delete temp;
    }

    void DeleteAt(int pos){
        //make a temporary pointer
            Node*current = head;
        //moving the pointer to the position
            int i=1;
            while(i<pos){
                current = current->next;
                i++;
            }
        //store the element temporarily
        Node*temp = current->next;
        //cut the links
        current->next = temp->next;
        (current->next)->prev = current;
        //deleting the node
        delete temp;
    }

    int CountItems(){
            //make the pointer counter
            Node* Count = head;
            //looping the counter
            int i=0;
            while(Count->next != NULL){
                    i++;
                Count=Count->next;
            }
            return i;
    }
    int display(){
        //make a temporary pointer
        if(head == NULL)cout<< "It's empty. "<<endl;
        else{
            Node*current = head;
            while(current->next != NULL){
                current = current->next;
                cout<< current->data << "->" ;
            }
            cout<< "NULL"<<endl;
        }
    }




};

int main(){
    Doublell dll1;
    for(int i= 0; i < 11; i++){
        dll1.Insert(i);
    }
    dll1.display();

    dll1.Insert(11);
    dll1.display();

    int x,y;
    cout<< "please enter the position at which you want to insert and the elements you want to insert respectively: "<<endl;
    cin>>y;
    cin>>x;
    int a = dll1.CountItems();
    cout<< a <<endl;
    if(y<=a){
        dll1.InsertAt(y,x);
    }
    else  cout<<"Linked List does not have that many elements "<<endl;
    dll1.display();

    dll1.Delete();
    dll1.display();

    cout<< "The number of items in your list is " <<dll1.CountItems()<<endl;
    cout<< "Please enter the position at which you want to delete the element at: "<<endl;
    int z;
    cin>> z;
    if(z<=a){
        dll1.DeleteAt(z);
    }
    else  cout<<"Linked List does not have that many elements "<<endl;
    dll1.display();
}



