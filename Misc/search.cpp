#include <iostream>

using namespace std;

int bruteForce(int a[], int n, int val){
    for (int i=0; i<n; i++){
        if (a[i] == val){
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[], int n, int val){
    int left = 0;
    int right = n-1;

    while(left<=right){
        int mid = (left+right)/2;

        if (a[mid]==val){
            return mid;
        }
        
        if (a[mid] > val){
            right = mid-1;
        }

        else{
            left = mid+1;
        }
    }
    return -1;
}



int main(int argc, char const *argv[])
{
    int size = 4;
    int m[size] = {2,3,1,4};
    // cout<<bruteForce(m,size,stoi(argv[1]))<<endl;
    cout<<binarySearch(m,size,stoi(argv[1]))<<endl;
    return 0;
}
