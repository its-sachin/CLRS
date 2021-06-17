#include <iostream>
#include <limits>

using namespace std;

void countingSort(int a[], int n, int k) {

    //stable, just change datatype for usage

    int c[k+1] = {0};
    
    for (int i=0; i<n; i++){
        c[a[i]] +=1;
    }

    for (int i=1; i<=k; i++){
        c[i] += c[i-1];
    }


    int b[n];
    
    for (int i=n-1; i>=0; i--){
        b[c[a[i]]-1] = a[i];
        c[a[i]] -= 1;
    }

    for (int i=0; i<n; i++) {
        a[i] = b[i];
    }

}

void countingSortNS(int a[], int n, int k) {

    //not stable, cannot be used for arbitrary dataype 

    int c[k+1] = {0};
    
    for (int i=0; i<n; i++){
        c[a[i]] +=1;
    }

    int j=0;
    for (int i=0; i<=k; i++){
        int k = 0;
        while(k<c[i]){
            a[j+k] = i;
            k+=1;
        }
        j +=c[i];
    }

    

}


int main(int argc, char const *argv[])
{
    int size=8;
    int array[size] = {2,5,3,0,2,3,0,3};

    std::cout<<"ACTUAL: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<""<<std::endl;

    countingSortNS(array,size,5);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
