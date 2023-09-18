 #include<stdio.h>
 #include<stdlib.h>
 
 int compare(const void *x, const void*y)
 {
     int a=*(int *)x;
     int b=*(int *)y;
     if (a<b)
         return -1;
     if (a>b)
         return 1;
     return 0;
 }
 int main(void)
 {
     int *num;
     int N,i;
     scanf("%d", &N);
     num=(int *)malloc(sizeof(int)*N);
     for(i=0;i<N;i++)
         scanf("%d", &num[i]);
     qsort(num, N, sizeof(int), compare);
     for (i=0; i<N; i++){
         printf("%d\n", num[i]);
     }
     free(num);
     return 0;}
 