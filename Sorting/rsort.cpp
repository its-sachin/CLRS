#include <iostream>
#include <limits>

using namespace std;

void csort(string a[], int n, int k, int digit) {

    int c[k+1] = {0};
    
    for (int i=0; i<n; i++){
        c[(int)a[i].at(digit)-48] +=1;
    }

    for (int i=1; i<=k; i++){
        c[i] += c[i-1];
    }

    string b[n];
    
    for (int i=n-1; i>=0; i--){
        b[c[(int)a[i].at(digit)-48]-1] = a[i];
        c[(int)a[i].at(digit)-48] -= 1;
    }

    for (int i=0; i<n; i++) {
        a[i] = b[i];
    }

}

void rsort(string a[], int n, int d, int k){
    //n-size of array
    //d-number of digits in each number(if not same then first append 0)
    //k-number of pooible values for digits(should be less than 10)
    for (int i=d-1; i>=0; i--){
        csort(a,n,k,i);
    }
}

int main(int argc, char const *argv[])
{
    int size=7;
    string array[size] = {"329","457","657","839","436","720","355"};

    std::cout<<"ACTUAL: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<""<<std::endl;

    rsort(array,size,3,9);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
