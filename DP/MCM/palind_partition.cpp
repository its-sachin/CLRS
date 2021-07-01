#include <iostream>

using namespace std;

bool isPalind(const string &str, int i, int j){

    while(i<j){
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;


}


int palindPartRec(const string &str, int i, int j, int** res){

    if(res[i][j]!=-1){
        return res[i][j];
    }

    if(isPalind(str,i,j)){
        res[i][j]=0;
        return 0;
    }

    int ans = INT32_MAX;
    for(int k=i; k<j; k++){
        int curr = palindPartRec(str,i,k,res)+1+palindPartRec(str,k+1,j,res);
        ans = min(ans,curr);
    }
    res[i][j]=ans;
    return ans;
}

int palindPart(const string &str)
{
    int N = str.size();
    int** res = new int*[N];
    for(int i=0;i<N;i++){
        res[i] = new int[N];
        for(int j=0;j<N;j++){
            res[i][j]=-1;
        }
    }
    return palindPartRec(str,0,N-1,res);
}

int main(int argc, char const *argv[])
{
    string n;
    cin>>n;
    
    cout<<palindPart(n)<<endl;
    return 0;
}