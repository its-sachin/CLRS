#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[101][101];

int eggDrop(int eggs,int floor){
    if(floor ==1 || floor ==0 || eggs==1) {
        return floor;
    }

    if(dp[eggs][floor]!=-1){
        return dp[eggs][floor];
    }

    int ans = INT32_MAX;
    int low = 1;
    int high = floor;
    while(low<high){
        int k = (low+high)/2;
        int up = eggDrop(eggs,floor-k);
        int bot = eggDrop(eggs-1,k-1);

        ans = min(ans,max(up,bot)+1);

        if(up==bot){
            break;
        }
        else if(up>bot){
            low = k+1;
        }
        else{
            high=k;
        }

    }

    return dp[eggs][floor] = ans;
}

int main(int argc, char const *argv[])
{
    int eggs;
    cin>>eggs;
    

    int floor;
    cin>>floor;
    
    memset(dp,-1,sizeof(dp));
    cout<<eggDrop(eggs,floor)<<endl;
    return 0;
}