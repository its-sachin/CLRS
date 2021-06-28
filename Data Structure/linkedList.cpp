#include <iostream>

using namespace std;

class Node{

private:
    int val;
    Node* next;
    
public:
    Node(int value){
        val = value;
        next = nullptr;
    }

    Node(int value, Node* n){
        val = value;
        next = n;
    }

    int getVal(){
        return val;
    }

    Node* getNext(){
        return next;
    }

    void setNext(Node* n){
        next = n;
    }
    
};

class LinkedList{

private:
    Node* head;
    
public:
    LinkedList(){
        head = nullptr;
    }

    LinkedList(Node* h){
        head = h;
    }

    LinkedList(int val){
        head = new Node(val);
    }

    void insert(int val){
        if(head==nullptr){
            head=new Node(val);
        }
        else{
            head = new Node(val,head);
        }
    }

    void remove(int val){
        if(head==nullptr){
            return;
        }
        Node* curr = head;
        while(curr->getNext()){
            if(curr->getNext()->getVal()==val){
                curr->setNext(curr->getNext()->getNext());
                break;
            }
            curr=curr->getNext();
        }
    }

    Node* search(int val){
        Node* curr = head;
        while(curr){
            if(curr->getVal()==val){
                return curr;
            }
            curr=curr->getNext();
        }
        return nullptr;
    }

    void print(){
        Node* curr = head;
        while(curr){
            cout<<curr->getVal()<<" ";
            curr=curr->getNext();
        }
    }


    
};

int main(int argc, char const *argv[])
{
    LinkedList* l = new LinkedList();
    for(int i=0; i<10; i++){
        l->insert(i);
    }
    l->print();
    l->remove(7);
    l->remove(3);
    l->print();

    if(l->search(8)){
        cout<<l->search(8)->getVal()<<endl;
    }
    return 0;
}