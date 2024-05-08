#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    int arr[51];
    int maxx=0;
    int minn=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int x=arr[i];
        int count=0;
        for(int i=1;i<10;i++){
            int t=pow(2,i);
            if(t<=x&&x<t*2){
                if(i>maxx)maxx=i;
                break;
            }
        }
    }

    
    int num=0;
    
    num+=maxx;
    for(int i=0;i<n;i++){
        int x=arr[i];
        int count=minn;
        while(true){
            if(x==0){
            //    cout<<endl;
                break;
            }
            if(x%2==0){
                x=x/2;
            }else{
                x-=1;
                num++;
            }
       //     cout<<x<<" ";
        }
    }

    cout<<num;
    return 0;
}