#include <iostream>

using namespace std;

bool subsetSum(int array[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for (int i = 1; i <=sum; i++){
        dp[0][i] = false;
    }
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=sum; j++){
            if(array[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-array[i-1]];
            }
        }
        
    }

    return dp[n][sum];
}

bool equalSum(int array[], int n){

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum+=array[i];
    }
    
    if(sum%2==0){
        return subsetSum(array,n,sum/2);
    }   
    return false;
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a[i] = ai;
    }
    
    cout<<equalSum(a,n)<<endl;
    return 0;
}