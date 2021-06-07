#include <iostream>
#include <limits>

void merge(int array[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;

    int l[n1+1];
    int r[n2+1];

    for(int i=0;i<n1;i++){
        l[i] = array[left+i];
    }

    for(int i=0;i<n2;i++){
        r[i] = array[mid+i+1];
    }

    l[n1] = std::numeric_limits<int>::max();
    r[n2] = std::numeric_limits<int>::max();

    int i=0;
    int j=0;

    for(int k=left; k<=right; k++){

        if (l[i] <= r[j]){
            array[k] = l[i];
            i+=1;

        }

        else{
            array[k] = r[j];
            j+=1;
        }
    }
}

void msort(int array[], int left, int right) {

    if(left<right) {
        int mid = (right+left)/2;
        msort(array,left,mid);
        msort(array,mid+1,right);
        merge(array,left,mid,right);
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

    msort(array,0,size-1);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
