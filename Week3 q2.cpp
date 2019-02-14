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
    Circularll(){
        head = NULL;
    }

    int CountItems(){
        //temporary pointer
            Node* counter  = head;
        int i=1;
        while(counter->next != head ){
            counter = counter->next;
            i++;
        }
        return i;
    }
    void Insert(int val){
        //creating a new node
        //temp->data = val;
        Node*temp = new Node(val);
        //check if the list is empty
        if(head == NULL){
            head = temp;
            head->next = head;
        }
        //in case the list isn't empty
        else{
            //temporary pointer
            Node* current  = head;
            while(current->next != head){
                current = current->next;

            }
             //then link the current to the new
                current->next = temp;

            //link the new node
            temp->next = head;

        }
    }
   

    void Display(){
         //temporary pointer
          Node* current  = head;
          if(current == NULL) {
                cout << "No elements " << endl;
                return;
          }
          else{
                Node* current  = head;
                while(current->next != head){
                        cout<< current->data << "->" ;
                    current = current->next;

                }

                //ptinting the last element
                cout<< current->data << "->" ;
                cout<< "NULL"<<endl;
          }
    }

    void InsertAt(int pos, int val){

        //creating a new node
        //temp->data = val;
        Node*temp = new Node(val);
         //move the pointer to the new node
        //in case of empty list
        if(head == NULL){
            head = temp;
            head->next = head;
        }
        //in case the list is not empty
        else{
         //temporary pointer
            Node* current  = head;
         //moving to the pos
             int i=1;
             while( i < (pos-1)){
                current = current->next;
                i++;
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
            while((current->next)->next != head){
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
         while( i < pos-1){
            current = current->next;
            i++;
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
    csll1.Display();



    int x,y;
    cout<< "please enter the position at which you want to insert and the elements you want to insert respectively: "<<endl;
    cin>>y;
    cin>>x;
    int a = csll1.CountItems();
    cout<< "The number of items in your list is " << a <<endl;
    if(y<=a){
        csll1.InsertAt(y,x);
    }
    else  cout<<"Linked List does not have that many elements "<<endl;
    csll1.Display();

    csll1.Delete();

    csll1.Display();
    cout<< "The number of items in your list is " <<csll1.CountItems()<<endl;

    cout<< "Please enter the position at which you want to delete the element at: "<<endl;
     int z;
    cin>> z;
    if(z<=a){
        csll1.DeleteAt(z);
    }
    else  cout<<"Linked List does not have that many elements "<<endl;

    csll1.Display();
    return 0;
}



