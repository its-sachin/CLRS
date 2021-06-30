#include <iostream>

using namespace std;

int minCoins(int array[], int n, int sum){
    
    int dp[n+1][sum+1];

    for (int i = 0; i <=sum; i++){
        dp[0][i] = INT32_MAX-1;
    }

    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=sum; j++){
            if(array[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j],1+ dp[i][j-array[i-1]]);
            }
            cout<<i<<" "<<j<<endl;
        }
        
    }

    return dp[n][sum];
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
    
    cout<<minCoins(a,n,sum)<<endl;
    return 0;
}