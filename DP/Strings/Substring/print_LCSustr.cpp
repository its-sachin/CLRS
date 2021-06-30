#include <iostream>

using namespace std;


string lcSubstrPrint(string a, string b){
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

    pair<int,int> dest = {0,0};
    for (int i=1; i<=n; i++){
        for (int j=1; j <=m; j++){
        
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                if(dp[dest.first][dest.second]<dp[i][j]){
                    dest = {i,j};
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    string ans = "";
    int i=dest.first;
    int j=dest.second;

    while(i>0 and j>0){
        if(a[i-1]==b[j-1]){
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
    
    string b;
    cin>>b;

    cout<<lcSubstrPrint(a,b)<<endl;  
 
    return 0;
}