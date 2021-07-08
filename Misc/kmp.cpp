#include <iostream>

using namespace std;

bool kmp(int a[], int b[], int n, int m){

    //O(n+m)

    //setting the prefix array
    int prefix[m];
    int j=0;
    int i=1;
    prefix[0]=0;
    while(i<m){
        if(b[i]==b[j]){
            prefix[i]=j+1;
            i+=1;
            j+=1;
        }
        else{
            if(j==0){
                prefix[i]=0;
                i+=1;
            }
            else{
                j=a[j-1];
            }
        }
    }

    i=0;
    j=0;
    while(i<n and j<m){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            j=prefix[j];
            if(j==0){
                i++;
            }
        }
    }
    return j==m;

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a[i] = ai;
    }
    
    int m;
    cin>>m;
    
    int b[m];
    for(int i=0; i<m; i++){
        int ai;
        cin>>ai;
        b[i] = ai;
    }

    cout<<lcsubstr(a,b,n,m)<<endl;
    return 0;
}