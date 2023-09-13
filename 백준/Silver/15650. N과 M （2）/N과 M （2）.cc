#include <stdio.h>

int N,M;

int a[10];

void f(int x,int y){
    if(y==M){
        for(int i=0;i<M;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }

    for(int i=x;i<=N;i++){
        a[y] = i;
        f(i+1,y+1);
    }

    return;
}

int main(){
    scanf("%d %d",&N,&M);

    f(1,0);

    return 0;
}