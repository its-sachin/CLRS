#include <iostream>
#include <limits>
#include <time.h>

using namespace std;

//copy line 9-47 for best case

void randomize(int a[], int left, int right, int swapper){
    srand(time(0));
    int r = (rand())%(right-left+1) + left;
    swap(a[swapper],a[r]);
}

pair<int,int> partEquality(int a[], int left, int right){


    randomize(a,left,right,right);
    int i = left-1;
    int k = left-1;
    int val = a[right];

    for (int j=left; j<=right;j++){
        if (a[j]==val){
            k+=1;
            swap(a[j],a[k]);
        }

        else if (a[j]<val){
            i+=1;
            swap(a[j],a[i]);
            k+=1;
            if (k!=i){
                swap(a[j],a[k]);
            }
        }
    }
    return {i,k};
}

void qsortEquality(int a[], int left, int right){
    if (left<right){
        pair<int,int> part = partEquality(a,left,right);
        qsortEquality(a,left,part.first);
        qsortEquality(a,part.second+1,right);
    }
}

int partLomuto(int a[], int left, int right){

    // partition about rightmost(if not randomized)

    randomize(a,left,right,right);
    int i = left-1;
    int val = a[right];

    for (int j=left; j<right;j++){
        if (a[j]<=val){
            i+=1;
            swap(a[j],a[i]);
        }
    }
    i+=1;
    swap(a[i],a[right]);
    return i;
}

void qsortLomuto(int a[], int left, int right){
    if (left<right){
        int part = partLomuto(a,left,right);
        qsortLomuto(a,left,part-1);
        qsortLomuto(a,part+1,right);
    }
}


int partHoare(int a[], int left, int right) {

    // partition about leftmost(if not randomized)

    randomize(a,left,right,left);
    int val = a[left];
    int i = left-1;
    int j = right+1;

    while(true){

        do {
            i++;
        } 
        while (a[i] < val);

        do {
            j--;
        } 
        while (a[j] > val);

        if (i >= j){
            return j;
        }
 
        swap(a[i], a[j]);

    }

}


void qsortHoare(int a[], int left, int right){
    if (left<right){
        int part = partHoare(a,left,right);
        qsortHoare(a,left,part);
        qsortHoare(a,part+1,right);
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

    qsortEquality(array,0,size-1);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
