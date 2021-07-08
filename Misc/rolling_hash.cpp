#include <iostream>

using namespace std;

bool rollingHash(string text, string pat, int mod){
    if(pat.size()>text.size())
        return false;
    int m = 1;
    int hPat=0;
    int hTex=0;
    for(int i=pat.size()-1; i>=0; i--){
        hPat+=(m*(pat[i]-'a'+1))%mod;
        hTex+=(m*(text[i]-'a'+1))%mod;
        if(i!=0)        
            m=(m*26)%mod;
    }

    int start=0;
    while(start+pat.size()<=text.size()){
        
        if(hTex==hPat){
            bool found = true;
            for (int i = 0; i < pat.size(); i++){
                if(text[start+i]!=pat[i]){
                    found=false;
                    break;
                }
            }   
            if(found){
                return true;
            }        
        }
        hTex -= (m*(text[start]-'a'+1))%mod;
        hTex= (hTex*26)%mod;
        start+=1;
        hTex +=text[start+pat.size()-1]-'a'+1;

    }
    return false;
}

int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;
    
    cout<<rollingHash(a,b,1000)<<endl;
    return 0;
}