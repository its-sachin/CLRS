#include <iostream>

using namespace std;


int lcs(string a, string b){
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for(int i=1; i<=m; i++){
        dp[0][i]=0;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j <=m; j++){
        
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int scs(string a, string b){
    int n = a.size();
    int m = b.size();

    return (n+m-lcs(a,b));
}


int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;

    cout<<scs(a,b)<<endl;   
    return 0;
}