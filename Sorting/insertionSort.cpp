#include <iostream>



void insertionSort(int array[], int left, int right) {

    for (int i= left+1; i<=right; i++){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
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

    insertionSort(array,0,size-1);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
