#include <bits/stdc++.h>

using namespace std;

void recursion(int n, int start, int to, int by)
{
    if(n == 1)
        printf("%d %d\n", start, to);
    else
    {
        recursion(n-1,start,by,to);
        printf("%d %d\n",start,to);
        recursion(n-1,by,to,start);
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1<<num) -1 << "\n";
    recursion(num,1,3,2);
}