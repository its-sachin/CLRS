#include <iostream>

using namespace std;


class Stack{

private:

    int size;
    int top;
    int* array;

public:

    Stack(int maxSize){
        size = maxSize;
        top = -1;
        array = new int[size];
    }

    bool isEmpty(){
        return (top==-1);
    }

    bool isFull(){
        return (top==size-1);
    }

    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top+=1;
        array[top]=x;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top-=1;
        return array[top+1];
    }

};


int main(int argc, char const *argv[])
{
    return 0;
}