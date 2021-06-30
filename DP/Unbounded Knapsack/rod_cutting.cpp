#include <iostream>

using namespace std;

int rodCutting(int val[], int length[], int n, int w){
    int dp[n+1][w+1];
    for(int i=0; i<n+1; i++){
        dp[i][0]=0;
    }
    for(int i=0; i<w+1; i++){
        dp[0][i]=0;
    }

    for(int i=1; i<n+1;i++){
        for(int j=1; j<w+1;j++){
            if(length[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-length[i-1]]+val[i-1]);
            }
        }
    }
    return dp[n][w];
}

int main(int argc, char const *argv[])
{
    int w;
    cin>>w;

    int n;
    cin>>n;
    
    int length[n];
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        length[i] = ai;
    }
    
    int val[n];
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        val[i] = ai;
    }

    cout<<rodCutting(val,length,n,w)<<endl;
    return 0;
}