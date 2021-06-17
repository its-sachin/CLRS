#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int inc(double ai, int n){
    return n*ai;
}

void isort(vector<double> &a){
    for (auto it = a.begin(); it != a.end(); it++)
    {        
        auto const p = upper_bound(a.begin(), it, *it);
          
        rotate(p, it, it+1);        
    }
}


void bsort(double a[], int n){

    //change inc() for changinf way of distribution in vectors
    //used inbuilt vector sorting algo and isort, can write another algo sorting a list(vector) 

    vector<double> b[n];
    for (int i=0; i<n; i++){
        b[inc(a[i],n)].push_back(a[i]);
    }

    for (int i=0; i<n; i++){
        sort(b[i].begin(),b[i].end());
        // isort(b[i]);
    }

    int j=0;
    for(int i=0; i<n; i++) {
        if (!b[i].empty()){
            for (double v: b[i]){
                a[j] = v;
                j+=1;
            }
        }
    }
 
}

int main(int argc, char const *argv[])
{
    int size=10;
    double array[size] = {.78,.17,.39,.26,.72,.94,.21,.12,.23,.68};

    std::cout<<"ACTUAL: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<""<<std::endl;

    bsort(array,size);

    std::cout<<"SORTED: ";
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }

    std::cout<<""<<std::endl;
    return 0;
}
