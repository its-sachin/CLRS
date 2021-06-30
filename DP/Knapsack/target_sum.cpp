#include <iostream>

using namespace std;

int numOfSubset(int array[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for (int i = 1; i <=sum; i++){
        dp[0][i] = 0;
    }
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=sum; j++){
            if(array[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-array[i-1]];
            }
        }
        
    }

    return dp[n][sum];
}

int targetSum(int array[], int n, int sum){

    int sumArray = 0;
    for (int i = 0; i < n; i++){
        sumArray+=array[i];
    }

    if((sumArray+sum)%2!=0){
        return 0;
    }

    int s2 = (sumArray+sum)/2;

    return numOfSubset(array,n,s2);
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

    int sum;
    cin>>sum;
    
    cout<<numOfSubset(a,n,sum)<<endl;
    return 0;
}