#include <iostream>

using namespace std;



int mcmRec(int array[], int i, int j, int** res){
    if(i>=j){
        return 0;
    }
    
    if(res[i][j]!=-1){
        return res[i][j];
    }

    int ans = INT32_MAX;
    for(int k=i; k<j; k++){
        int prod = array[i-1]*array[k]*array[j];
        int curr = mcmRec(array,i,k,res)+prod+mcmRec(array,k+1,j,res);
        if(curr<ans){
            ans = curr;
        }
    }
    res[i][j]=ans;
    return ans;
}

int mcm(int N, int arr[])
{
    int** res = new int*[N];
    for(int i=0;i<N;i++){
        res[i] = new int[N];
        for(int j=0;j<N;j++){
            res[i][j]=-1;
        }
    }
    return mcmRec(arr,1,N-1,res);
}

int main(int argc, char const *argv[])
{
    return 0;
}