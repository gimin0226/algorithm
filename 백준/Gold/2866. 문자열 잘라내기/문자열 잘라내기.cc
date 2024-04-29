#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string str[1001];
    
    for(int i=0;i<n;i++){
        string str1;
        cin>>str1;
        if(i==0)continue;
        for(int j=0;j<m;j++){
            str[j]+=str1[j];
        }
        
    }
    int count=0;
    unordered_map<string,bool> um;
    while(true){
       
        for(int i=0;i<m;i++){
            if(um.count(str[i])){
                cout<<count;
                return 0; 
            }
            else{
            um.insert({str[i],true});
            }
        }
        count++;
        if(str[0].length()==1){
            cout<<count;
            return 0;
        }
        um.clear();
        for(int i=0;i<m;i++){
            str[i]=str[i].substr(1);
        }
    }

    
    
    return 0;
}