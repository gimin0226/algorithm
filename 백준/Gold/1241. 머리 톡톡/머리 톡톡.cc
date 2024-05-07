#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int arr[1000001]={0};
    int n;
    int arr3[100001];
    unordered_map<int,int> um;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr3[i];
        if(um.find(arr3[i])!=um.end()){
            um[arr3[i]]++;
        }else{
            um.insert({arr3[i],1});
        }
    }

    for(int i=1;i<=n;i++){
        auto it=um.find(arr3[i]);
        int num=it->second;
      //  cout<<arr3[i]<<" "<<num<<endl;
        if(num==0)continue;
        else if(num>=2)arr[arr3[i]]+=num-1;
        int x=arr3[i];
        int t=2;
        while(true){
            if(x*t>1000000)break;
            arr[x*t]+=num;
            t++;
        }
        if(num>=2)it->second=0;
    }

    for(int i=1;i<=n;i++){
        cout<<arr[arr3[i]]<<'\n';
    }
    
}