#include <iostream>
#include <unordered_map>

using namespace std;

// void print(int** a,int n,int m){
//     for(int i=0;i<=n;i++){
//         cout<<"[";;
//         for(int j=0;j<=m;j++){
//             cout<<a[i][j]<<" ";
//         }
//         cout<<"]"<<endl;
//     }
//     cout<<" "<<endl;
// }

int lcsubst(string a, string b){
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];

    // here dp[i][j] represents length of common substring including a[i] and b[j]

    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for(int i=1; i<=m; i++){
        dp[0][i]=0;
    }

    int ma=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j <=m; j++){
        
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ma = max(ma,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
            // cout<<i<<" "<<j<<endl;
            // print(dp,n,m);
        }
    }

    return ma;
}


int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;

    cout<<lcsubst(a,b)<<endl;   
    return 0;
}