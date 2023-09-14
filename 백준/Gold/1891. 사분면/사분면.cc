#include<bits/stdc++.h>
using namespace std;

long long X, Y;
long long d;
string str;
long long start_x;
long long end_x;
long long start_y;
long long end_y;
long long SIZE = 1;
long long x, y;
long long a, b;

void find_XY() {
    start_x = 0; end_x = SIZE - 1;
    start_y = 0; end_y = SIZE - 1;

    for (long long i = 0; i < d; i++) {
        switch (str[i]) {
        case '1':
            start_y = (start_y + end_y) / 2 + 1;
            end_x = (start_x + end_x) / 2;
            break;
        case '2':
            end_y = (start_y + end_y) / 2;
            end_x = (start_x + end_x) / 2;
            break;
        case '3':
            start_x = (start_x + end_x) / 2 + 1;
            end_y = (start_y + end_y) / 2;
            break;
        case '4':
            start_y = (start_y + end_y) / 2 + 1;
            start_x = (start_x + end_x) / 2 + 1;
            break;
        }
    }
  //  prlong longf("%d %d %d %d\n", start_x, end_x, start_y, end_y);
    x = start_x - Y; y = end_y + X;
}

void recursion(string str,long long num) {
    if (!(start_x <= x && x <= end_x && start_y <= y && y <= end_y))return;
    if (num == d) {
        // prlong longf("%d %d %d %d %d %d\n", x, y, start_x, end_x, start_y, end_y);
        cout << str;
        exit(0);
    }
    a = start_x; b = end_y;
    start_x = (start_x + end_x) / 2 + 1; end_y = (start_y + end_y) / 2;
    recursion(str+"3",num + 1 );
    start_x = a; end_y = b;

    a = end_x; b = start_y;
    end_x = (start_x + end_x) / 2; start_y = (start_y + end_y) / 2 + 1;
    recursion(str+"1",num + 1);
    end_x = a; start_y = b;

    a = start_x; b = start_y;
    start_x = (start_x + end_x) / 2 + 1; start_y = (start_y + end_y) / 2 + 1;
    recursion(str+"4",num + 1);
    start_x = a; start_y = b;

    a = end_x; b = end_y;
    end_x = (start_x + end_x) / 2; end_y = (start_y + end_y) / 2;
    recursion(str+"2",num + 1);
    end_x = a; end_y = b;
}
int main() {
    cin >> d >> str;
    cin >> X >> Y;
    for (long long i = 0; i < d; i++) {
        SIZE *= 2;
    }
    find_XY();
    start_x = 0; start_y = 0; end_x = SIZE - 1; end_y = SIZE - 1;
    recursion("", 0);
    cout << "-1";
}
