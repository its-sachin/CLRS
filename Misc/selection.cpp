#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

int getMin(int a[], int n){
    
    //n-1 comparisions

    int min = a[0];
    for (int i=1;i <n; i++){
        if (min>a[i]){
            min = a[i];
        }
    }
    return min;
}

int getMax(int a[], int n){
    
    //n-1 comparisions

    int max = a[0];
    for (int i=1;i <n; i++){
        if (max<a[i]){
            max = a[i];
        }
    }
    return max;
}

pair<int,int> getMinMax(int a[], int n){

    //3(n/2) comparisions
    //CONSTRAINT: array is not empty

    int min,max,i;
    if (n%2==0){

        if (a[0]>=a[1]){
            max=a[0];
            min=a[1];
        }
        else{
            max=a[1];
            min=a[0];
        }
        i=2;
    }

    else{
        min=a[0];
        max=a[1];
        i=1;
    }

    while(i<n){
        if (a[i]>a[i+1]){
            if (max<a[i]){
                max=a[i];
            }
            if(min>a[i+1]){
                min=a[i+1];
            }
        }
        else{
            if (max<a[i+1]){
                max=a[i+1];
            }
            if (min>a[i]){
                min=a[i];
            }
        }
        i+=2;
    }
    return {min,max};

}


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



void randomize(int a[], int left, int right, int swapper){
    srand(time(0));
    int r = (rand())%(right-left+1) + left;
    swap(a[swapper],a[r]);
}

// int medianize(int a[], int left, int right, int swapper){
//     int i=0;
//     int n = ceil((right-left+1)/5);
//     int medians[n];
//     while(i<n){
//         int l = left+5*i;
//         int r = left+5*(i+1)-1;
//         if (i==n-1){
//             r = right;
//         }
//         insertionSort(a,l,r);
//         medians[i] = a[(l+r)/2];
//         i+=1;
//     }
//     int x = 
// }

int partHoare(int a[], int left, int right){

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

int selection(int a[], int left, int right, int k){

    //O(n) time expected
    //O(n^2) time worst

    if (left==right){
        return a[right];
    }

    int p = partHoare(a,left,right);
    int i = p-left+1;

    if (i==k){
        return a[i];
    }
    else if (k<i){
        return selection(a,left,p-1,k);
    }
    else{
        return selection(a,p+1,right,k-i);
    }
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

int selectEquality(int a[], int left, int right, int k){

    //O(n) time expected
    //O(n^2) time worst
    //use when there are lots of equal elements


    if (left==right){
        return a[right];
    }

    pair<int,int> p = partEquality(a,left,right);
    int k1 = p.first-left+1;
    int k2 = p.second-left+1;

    if (k<=k2 && k>k1){
        return a[k2];
    }

    else if (k>k2){
        return selection(a,p.second+1,right,k-k2);
    }

    else{
        return selection(a,left,p.first,k);
    }

}



int main(int argc, char const *argv[])
{
    int size = 9;
    int m[size] = {1,5,10,20,100,130,190,400,900};

    return 0;
}
