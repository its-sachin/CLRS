#include <iostream>

using namespace std;

string longestPalind(string a){
    int n = a.size();

    int dp[n+1][n+1];

    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for(int i=1; i<=n; i++){
        dp[0][i]=0;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j <=n; j++){
        
            if(a[i-1]==a[n-j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
                if(dp[i-1][j-1]!=0 and j-1-dp[i-1][j-1]+i-1!=n){
                    int u=i-1;
                    int v=j-1;
                
                    while(u>0 and v>0 and dp[u][v]!=0){
                        dp[u][v]=0;
                        u-=1;
                        v-=1;
                    }
                }
            }
        }
    }
    
    if(dp[n][n]!=0 and dp[n][n]!=n){
        int u=n;
        int v=n;
    
        while(u>0 and v>0 and dp[u][v]!=0){
            dp[u][v]=0;
            u-=1;
            v-=1;
        }
    }

    pair<int,int> ma = {0,0};
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j]>=dp[ma.first][ma.second]){
                ma = {i,j};
            }
        }
    }

    string ans = "";

    int i=ma.first;
    int j=ma.second;

    while(i>0 and j>0){
        if(dp[i][j]>0){
            ans.push_back(a[i-1]);
            i-=1;
            j-=1;
        }
        else{
            break;
        }
    }

    i=0;
    j=ans.size()-1;

    while(i<j){
        swap(ans[i],ans[j]);
        i+=1;
        j-=1;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    string a;
    cin>>a;

    cout<<longestPalind(a)<<endl;   
    return 0;
}