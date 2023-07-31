#include <stdio.h>
 
int f(int x, int y, int z) {
    if (y>1) {
        long long a = f(x, y / 2, z);
        if (y % 2) return ((a * a) % z * x) % z;
        else return (a * a) % z;
    }
    else return x;
}
 
int main() {
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
 
    int a = f(x % z, y, z);
    printf("%d\n", a);
    return 0;
}