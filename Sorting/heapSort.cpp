#include <iostream>

using namespace std;


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int i, int heapSize){
    int l = 2*i+1;
    int r = 2*i+2;
    
    int largest = i;
    if (l<heapSize && heap[l]>heap[i]){
        largest = l;
    }
    if (r<heapSize && heap[r] > heap[largest]){
        largest = r;
    }

    if (largest != i){
        swap(&heap[largest],&heap[i]);
        heapify(heap,largest,heapSize);
    }
}

bool heapSort(int heap[], int n){
    int heapSize = n;
    for (int i=n/2-1; i>=0; i--){
        heapify(heap,i,heapSize);
    }
    for (int i=n-1;i>0;i--){
        swap(&heap[0],&heap[i]);
        heapSize = heapSize-1;
        heapify(heap,0,heapSize);
    }
}

int main(int argc, char const *argv[])
{
    int size=10;
    int array[size] = {9,3,8,-1,33,-43,9,11,-8,0};

    std::cout<<"ACTUAL: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<""<<std::endl;

    heapSort(array,size);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
