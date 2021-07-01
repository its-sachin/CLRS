#include <iostream>

using namespace std;


string lcsPrint(string a, string b){
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
    
    string ans = "";
    int i=n;
    int j=m;

    while(i>0 and j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i-=1;
            j-=1;
        }
        else{
            if(dp[i-1][j]>=dp[i][j-1]){
                i-=1;
            }
            else{
                j-=1;
            }
        }
    }

    i=0;
    j=dp[n][m]-1;

    while(i<j){
        swap(ans[i],ans[j]);
        i+=1;
        j-=1;
    }
    return ans;
}

string lcsPrint1(string a, string b){
    int n = a.size();
    int m = b.size();

    string dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        dp[i][0]="";
    }
    for(int i=1; i<=m; i++){
        dp[0][i]="";
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j <=m; j++){
        
            if(a[i-1]==b[j-1]){
                
                dp[i][j] = dp[i-1][j-1];
                dp[i][j].push_back(a[i-1]);
            }
            else{
                if(dp[i-1][j].size() >= dp[i][j-1].size()){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m];
}


int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;

    cout<<lcsPrint(a,b)<<endl;  
    cout<<lcsPrint1(a,b)<<endl;   
    return 0;
}