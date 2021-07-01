#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> dp;


bool scrRec(string a, string b){
    if(a==b){
        return true;
    }
    
    if(a.size()<2){
        return false;
    }
    string key = a;
    key.push_back(' ');
    key.append(b);

    if(dp.find(key) != dp.end())
        return dp.at(key);

    int n = a.size();

    for(int k=1; k<n;k++){
        if((scrRec(a.substr(0,k),b.substr(0,k)) and scrRec(a.substr(k,n-k),b.substr(k,n-k))) || 
            (scrRec(a.substr(0,k),b.substr(n-k,k)) and scrRec(a.substr(k,n-k),b.substr(0,n-k)))){
            dp.insert({key,true});
            return true;
        }

    }
    dp.insert({key,false});
    return false;
}

int scramble(string a, string b){


    if(a.size()!=b.size())
        return false;

    dp.clear();
    return scrRec(a,b);
}

int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;
    
    cout<<scramble(a,b)<<endl;
    return 0;
}