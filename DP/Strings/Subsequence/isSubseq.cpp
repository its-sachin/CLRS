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

bool isSubseq(string a, string b){
    // is a subsequence of b

    if(a.size()>b.size())
        return false;
    else
        return (lcs(a,b)==a.size());

}

bool isSubseq1(string a, string b){
    
    if(a.size()>b.size())
        return false;
    else{

        int i=0;
        for(int j=0; j<b.size();j++){
            if(a[i]==b[j]){
                i++;
                if(i==a.size()){
                    break;
                }
            }
        }

        return (i==a.size());
    }
}

int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;

    cout<<isSubseq(a,b)<<endl;   
    return 0;
}