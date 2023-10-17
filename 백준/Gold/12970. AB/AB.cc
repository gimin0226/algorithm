#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    int n, k;
    cin >> n >> k;

    string str = "";
    for (int i = 1; i < n; i++) {
        //i:고정하는 B의 수
        //n-i: A의 수
        //i*(n-i): 가능한 최대 쌍 
        if (i * (n - i) < k) {  //최대 쌍이 k보다 작아서 만들 수 없으면 
            continue;
        }
        int x = n-i; //현재 존재하는 A의 수
        int y = i;  //현재 뒤에 존재하는 B의 수 
        int t = k;  //채워야하는 쌍
        while (true) {
            if (y == 0) {
                for (int i = 0; i < x; i++) {
                    str += "A";
                   
                }

                cout << str;
                return 0;
            }
            if (y <= t) {
                str += "A";
                t-=y;
                x--;
            //    cout << str<<endl;
            }
            else {
                str += "B";
                y--;
            //    cout << str << endl;
            }
        }



    }
    cout << "-1";
    return 0;
}