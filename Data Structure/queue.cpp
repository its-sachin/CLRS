#include <iostream>

using namespace std;

class Queue{

private:

    int size;
    int head;
    int tail;
    int* array;

    
public:
    Queue(int maxSize){
        size = maxSize;
        head = 0;
        tail = 0;
        array = new int[size];
    }

    bool isEmpty(){
        return (tail==head);
    }

    bool isFull(){
        return (head==(tail+1)%size);
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        array[tail]=x;
        tail=(tail+1)%size;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        int ans = array[head];
        head=(head+1)%size;
        return ans;
    }
    
};

int main(int argc, char const *argv[])
{
    return 0;
}