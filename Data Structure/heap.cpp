#include <iostream>
#include <limits>

using namespace std;

// parent ->i then 
// left child -> 2*i+1
// right child -> 2*i+2 

// parent(i)-> i//2 -1

class MaxHeap{

    // note: this heap will take indexes from 0.

private:
    int maxSize;
    int heapSize;
    int* heap;

    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:

    MaxHeap(int N){
        maxSize = N;
        heap = new int[N];
        heapSize = 0;
    }

    int parent(int i){
        return ((i+1)/2)-1;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    bool isFull(){
        return (maxSize==heapSize);
    }

    int getMax(){
        return heap[0];
    }


    void printHeap(){
        for (int i=0; i<heapSize; i++) {
            cout << heap[i] << " ";
        }
        cout<<""<<endl;
    }

    void heapify(int i){
        int l = left(i);
        int r = right(i);
        
        int largest = i;
        if (l<heapSize && heap[l]>heap[i]){
            largest = l;
        }
        if (r<heapSize && heap[r] > heap[largest]){
            largest = r;
        }

        if (largest != i){
            swap(&heap[largest],&heap[i]);
            heapify(largest);
        }
    }

    bool build(int a[], int n){

        // this overwrites previous heap and set it to the given array
        if (n>maxSize){
            cout<<"Heap Overflow"<<endl;
            return false;
        }
        heapSize = n;
        for(int i=0; i<n;i++){
            heap[i] = a[i];
        }
        for (int i=n/2-1; i>=0; i--){
            heapify(i);
        }
        return true;
    }

    bool heapSort(int a[], int n){
        if (!build(a,n)){
            return false;
        }
        for (int i=n-1;i>=0;i--){
            a[i] = heap[0];
            swap(&heap[0],&heap[i]);
            heapSize = heapSize-1;
            heapify(0);
        }
    }

    bool increase(int i, int val){
        if (i >= heapSize || val<heap[i]){
            cout<<"Invalid Increment"<<endl;
            return false;
        }

        heap[i] = val;
        while(i>=0 && heap[parent(i)] < heap[i]){
            swap(&heap[parent(i)],&heap[i]);
            i = parent(i);
        }
        return true;

    }

    bool insert(int val){
        if(isFull()){
            cout<<"Heap Overflow"<<endl;
            return false;
        }
        heap[heapSize]=numeric_limits<int>::min();
        heapSize+=1;
        return increase(heapSize-1,val);
    }

    int removeMax(){
        if (heapSize==0){
            cout<<"Empty Heap Error"<<endl;
            return numeric_limits<int>::min();
        }
        int max = heap[0];
        heap[0] = heap[heapSize-1];
        heapSize-=1;
        heapify(0);
        return max;
    }

};

int main(int argc, char const *argv[])
{
    int size=10;
    int array[size] = {9,3,8,-1,33,-43,9,11,-8,0};

    MaxHeap* h = new MaxHeap(15);
    h->build(array,size);
    h->printHeap();
    h->insert(55);
    h->printHeap();
    h->removeMax();
    h->printHeap();
    return 0;
}
