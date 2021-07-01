#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int res[205][205][2];
#define mod 1003

int boolParenRec(const string &str, int i, int j, bool isTrue){

    if(i>j){
        return 0;
    }

    if (i==j){
        if((isTrue and str[i]=='T')||(!isTrue and str[i]=='F'))
            return 1;
        return 0;
    }
     
    if(res[i][j][isTrue]!=-1){
        return res[i][j][isTrue];
    }

    int ans = 0;
    for(int k=i+1; k<j; k+=2){

        if(res[i][k-1][1]==-1)
            res[i][k-1][1] = boolParenRec(str, i, k-1, true);
        if(res[i][k-1][0]==-1)
            res[i][k-1][0] = boolParenRec(str, i, k-1, false);
        if(res[k+1][j][1]==-1)
            res[k+1][j][1] = boolParenRec(str, k+1, j, true);
        if(res[k+1][j][0]==-1)
            res[k+1][j][0] = boolParenRec(str, k+1, j, false);

        int lT =res[i][k-1][1];
        int lF = res[i][k-1][0];
        int rT = res[k+1][j][1];
        int rF =res[k+1][j][0];

        switch (int(str[k])){

        case 38:
            if(isTrue)
                ans += (lT*rT)%mod;
            else
                ans += ((lT*rF)%mod+(lF*rT)%mod+(lF*rF)%mod)%mod;
        break;

        case 124:
            if(isTrue)
                ans+=((lT*rF)%mod+(lF*rT)%mod+(lT*rT)%mod)%mod;
            else
                ans+=(lF*rF)%mod;
        break;

        case 94:
            if(isTrue)
                ans+=((lT*rF)%mod+(lF*rT)%mod)%mod;
            else
                ans+=((lF*rF)%mod+(lT*rT)%mod)%mod;
        }
    }
    res[i][j][isTrue] = ans%mod;
    return ans%mod;
}

int countWays(int N, const string &str){
    memset(res, -1, sizeof(res));
    return boolParenRec(str,0,N-1,true);
}

int main(int argc, char const *argv[])
{
    string n;
    cin>>n;
    
    cout<<countWays(n.size(),n)<<endl;
    return 0;
}