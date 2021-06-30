#include <iostream>

using namespace std;

int minSubsetDiff(int array[], int n){

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum+=array[i];
    }
    
    int maxSi = sum/2;
    bool dp[n+1][maxSi+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for (int i = 1; i <=maxSi; i++){
        dp[0][i] = false;
    }
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=maxSi; j++){
            if(array[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-array[i-1]];
            }
        }
        
    }

    for(int i=maxSi; i>=0; i--){
        if(dp[n][i]){
            return (sum-2*i);
        }
    }

    return sum;
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
    
    cout<<minSubsetDiff(a,n)<<endl;
    return 0;
}