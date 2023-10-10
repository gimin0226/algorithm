#include <iostream>
#define ll long long
#define mid(x,y) (x+y)/2;
using namespace std;

const int MAX = 1000005;

int V,Q,num,p,q, sidx;
ll x;
ll tree[MAX*4];


void update(int start, int end, int node, int index, ll val){

    if(index<start || index>end) return ;
    tree[node] += val;
    if(start==end) return  ;

    int mid = mid(start, end);

    update(start, mid, node*2, index, val);
    update(mid+1, end, node*2+1, index, val);

}


ll find(int left, int right, int start, int end, int node){

    if(right< start || end <left) return 0;
    if(left<=start && end<=right) return tree[node];

    int mid = (start+end)/2;
    return find(left, right, start, mid, node*2)
           + find(left, right, mid+1, end, node*2+1);
}



int main(){


    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>V>>Q; 

    while(Q--){

        cin>>num;

        if(num==1){
            cin>>p>>x;
            update(1, V, 1, p,x);
        }
        else {
            cin>>p>>q;
            cout<<find(p, q, 1, V, 1)<<'\n';
        }

    }
}